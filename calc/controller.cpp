#include "controller.h"
bool s21::Controller::check_line_ask_for_ALL_SIMBOLS(QString line) {
  QString str = ALL_SIMBOLS;
  for (QChar ch : line) {
    if (!str.contains(ch)) {
      return false;
    }
  }
  return true;
}

bool s21::Controller::check_line_is_int(const QString &str) {
  bool tmp = false;
  str.toInt(&tmp);
  return tmp;
}
bool s21::Controller::check_line_is_double(const QString &str) {
  bool tmp = false;
  str.toDouble(&tmp);
  return tmp;
}

void s21::Controller::main_deposit(QMap<QString, QString> &dict) {
  QString field_deposit_sum = dict["get_field_deposit_sum"];
  QString field_srok = dict["get_field_srok"];
  QString field_percent = dict["get_field_percent"];
  QString field_nalog = dict["get_field_nalog"];
  QString radio_kapitalizacia = dict["get_radio_kapitalizacia"];
  if (check_line_is_double(field_deposit_sum) &&
      check_line_is_int(field_srok) && check_line_is_double(field_percent) &&
      check_line_is_double(field_nalog)) {
    double deposit_sum = field_deposit_sum.toDouble(),
           srok = field_srok.toDouble(), percent = field_percent.toDouble(),
           nalog = field_nalog.toDouble();
    if (radio_kapitalizacia == "true") {
      QHash<QString, double> res =
          model->main_deposit_kapitalizacia(deposit_sum, percent, srok, nalog);
      emit res_q_hash_deposit(res);
    } else {
      QHash<QString, double> res = model->main_deposit_back_pays_every_month(
          deposit_sum, percent, srok, nalog);
      emit res_q_hash_deposit(res);
    }
  }
}

void s21::Controller::main_credits(QMap<QString, QString> &dict) {
  QString field_credit_sum = dict["get_field_credit_sum"];
  QString field_percent = dict["get_field_percent"];
  QString field_srok = dict["get_field_srok"];
  QString radio_but_annu = dict["get_radio_but_annu"];
  if (check_line_is_int(field_srok) && check_line_is_double(field_credit_sum) &&
      check_line_is_double(field_percent)) {
    double credit_sum = field_credit_sum.toDouble(),
           percent = field_percent.toDouble(), srok = field_srok.toDouble();
    if (radio_but_annu == "true") {
      QHash<QString, double> res =
          model->main_credit_annu(credit_sum, percent, srok);
      emit res_q_hash_credits(res);
    } else {
      QHash<QString, double> res =
          model->main_credit_diff(credit_sum, percent, srok);
      emit res_q_hash_credits(res);
    }
  }
}
void s21::Controller::main_calculator(QMap<QString, QString> &dict) {
  QString line_ask = dict["calculator_get_line_ask"];
  QString line_x = dict["calculator_get_line_x"];
  QString line_h = dict["calculator_get_line_h"];
  double x = line_x.toDouble();
  std::string line_ask_std = line_ask.toStdString();
  if (check_line_ask_for_ALL_SIMBOLS(line_ask) &&
      check_line_is_double(line_x)) {
    double _x = model->MainCalculation(line_ask_std, x);
    view->set_line_answer(_x);
  } else if (check_line_ask_for_ALL_SIMBOLS(line_ask) &&
             !check_line_is_double(line_x) && check_line_is_int(line_h)) {
    double x_begin = 0, x_end = 0, h = line_h.toInt();
    int X = 0;
    int N;
    x_begin = Y_MIN;
    x_end = Y_MAX;
    x_end += h;
    QVector<double> x, y;
    x.clear();
    y.clear();
    view->set_graph()->clearGraphs();
    view->set_graph()->xAxis->setRange(x_begin - 1, x_end + 1);
    view->set_graph()->yAxis->setRange(x_begin - 1, x_end + 1);
    X = x_begin;
    N = (x_end - x_begin) / h + 2;
    for (X = x_begin; X <= x_end; X += h) {
      double _y = model->MainCalculation(line_ask_std, X);
      x.push_back(X);
      y.push_back(_y);
    }
    view->set_graph()->addGraph();
    view->set_graph()->graph(0)->addData(x, y);
    view->set_graph()->replot();
    view->set_graph()->setInteraction(QCP::iRangeZoom, true);
    view->set_graph()->setInteraction(QCP::iRangeDrag, true);
  }
}
