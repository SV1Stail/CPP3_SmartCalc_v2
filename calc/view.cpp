#include "view.h"

// bool s21::View::check_q_line_for_ALL_SIMBOLS(const QLineEdit& line){
//     QString str = ALL_SIMBOLS;
//     for (QChar ch : line.text()) {
//       if (!str.contains(ch)) {
//         return false;
//       }
//     }
//     return true;
// }
void s21::View::handle_butt_go_to_deposClicked() { deposit->show(); }
void s21::View::handle_butt_go_to_creditClicked() { credits->show(); }
void s21::View::handle_butt_go_to_calcClicked() { calculator->show(); }

void s21::View::print_QMap(QMap<QString, QString> &dict) {
  QMapIterator<QString, QString> i(dict);
  while (i.hasNext()) {
    i.next();
    qDebug() << i.key() << ": " << i.value();
  }
  qDebug() << endl;
}

void s21::View::handle_calculator_butt_ravnoClicked() {
  QMap<QString, QString> dict = all_data_calculator();
  //     controller->print_QMap(dict);
  emit calculator_butt_ravnoClicked(dict);
  //    print_QMap(dict);
}
void s21::View::handle_credits_butt_ravnoClicked() {
  QMap<QString, QString> dict = all_data_credits();
  emit credits_butt_ravnoClicked(dict);

  //    print_QMap(dict);
}
void s21::View::handle_deposit_butt_ravnoClicked() {
  QMap<QString, QString> dict = all_data_deposit();
  QString str = dict["get_field_srok"];
  int srok = str.toInt();
  deposit->spisok_popolneniy(srok);
  emit deposit_butt_ravnoClicked(dict);
  //    print_QMap(dict);
}
void s21::View::handle_res_q_hash_deposit(
    const QHash<QString, double> &results) {
  deposit->set_field_nachislenie_percents(
      results["field_nachislenie_percents"]);
  deposit->set_field_nalog_sum(results["field_nalog_sum"]);
  deposit->set_field_sum_at_the_end(results["field_sum_at_the_end"]);
}
void s21::View::handle_res_q_hash_credits(
    const QHash<QString, double> &results) {
  credits->set_field_all_priece(results["field_all_priece"]);
  credits->set_field_pereplata(results["field_pereplata"]);
  if (results.contains("every_month_payment_diff_min")) {
    QString str =
        QString::number(results["every_month_payment_diff_min"], 'f', 2) +
        "..." +
        QString::number(results["every_month_payment_diff_max"], 'f', 2);
    credits->set_field_everymonth_payment(str);
  } else
    credits->set_field_everymonth_payment(results["field_everymonth_payment"]);
}
QMap<QString, QString> s21::View::all_data_calculator() {
  QMap<QString, QString> dict;
  if (calculator->get_line_ask()) {
    if (calculator->get_line_ask()->text() == "")
      dict["calculator_get_line_ask"] = "0";
    else
      dict["calculator_get_line_ask"] = calculator->get_line_ask()->text();
  }
  if (calculator->get_line_x()) {
    if (calculator->get_line_x()->text() == "")
      dict["calculator_get_line_x"] = "0";
    else
      dict["calculator_get_line_x"] = calculator->get_line_x()->text();
  }
  if (calculator->get_line_h()) {
    if (calculator->get_line_h()->text() == "")
      dict["calculator_get_line_h"] = "0";
    else
      dict["calculator_get_line_h"] = calculator->get_line_h()->text();
  }

  return dict;
}
QMap<QString, QString> s21::View::all_data_credits() {
  QMap<QString, QString> dict;
  if (credits->get_field_credit_sum()) {
    if (credits->get_field_credit_sum()->text() == "")
      dict["get_field_credit_sum"] = "0";
    else
      dict["get_field_credit_sum"] = credits->get_field_credit_sum()->text();
  }
  if (credits->get_field_percent()) {
    if (credits->get_field_percent()->text() == "")
      dict["get_field_percent"] = "0";
    else
      dict["get_field_percent"] = credits->get_field_percent()->text();
  }
  if (credits->get_field_srok()) {
    if (credits->get_field_srok()->text() == "")
      dict["get_field_srok"] = "0";
    else
      dict["get_field_srok"] = credits->get_field_srok()->text();
  }
  if (credits->get_radio_but_annu())
    dict["get_radio_but_annu"] =
        credits->get_radio_but_annu()->isChecked() ? "true" : "false";
  return dict;
}
QMap<QString, QString> s21::View::all_data_deposit() {
  QMap<QString, QString> dict;
  if (deposit->get_field_deposit_sum()) {
    if (deposit->get_field_deposit_sum()->text() == "")
      dict["get_field_deposit_sum"] = "0";
    else
      dict["get_field_deposit_sum"] = deposit->get_field_deposit_sum()->text();
  }
  if (deposit->get_field_srok()) {
    if (deposit->get_field_srok()->text() == "")
      dict["get_field_srok"] = "0";
    else
      dict["get_field_srok"] = deposit->get_field_srok()->text();
  }
  if (deposit->get_field_percent()) {
    if (deposit->get_field_percent()->text() == "")
      dict["get_field_percent"] = "0";
    else
      dict["get_field_percent"] = deposit->get_field_percent()->text();
  }
  if (deposit->get_field_nalog()) {
    if (deposit->get_field_nalog()->text() == "")
      dict["get_field_nalog"] = "0";
    else
      dict["get_field_nalog"] = deposit->get_field_nalog()->text();
  }

  if (deposit->get_radio_kapitalizacia())
    dict["get_radio_kapitalizacia"] =
        deposit->get_radio_kapitalizacia()->isChecked() ? "true" : "false";
  return dict;
}
void s21::View::set_line_answer(const double text) {
  calculator->set_line_answer(text);
}
void s21::View::set_field_nachislenie_percents(const double text) {
  deposit->set_field_nachislenie_percents(text);
}
void s21::View::set_field_nalog_sum(const double text) {
  deposit->set_field_nalog_sum(text);
}
void s21::View::set_field_sum_at_the_end(const double text) {
  deposit->set_field_sum_at_the_end(text);
}

void s21::View::set_field_everymonth_payment(const double text) {
  credits->set_field_everymonth_payment(text);
}
void s21::View::set_field_pereplata(const double text) {
  credits->set_field_pereplata(text);
}
void s21::View::set_field_all_priece(const double text) {
  credits->set_field_all_priece(text);
}
QCustomPlot *s21::View::set_graph() { return calculator->get_graph(); }
