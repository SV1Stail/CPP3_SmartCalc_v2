#ifndef VIEW_H
#define VIEW_H
#include <QDebug>
#include <QMap>
#include <QString>
#include <QtWidgets>

#include "QHash"
#include "calculator.h"
#include "credits.h"
#include "deposit.h"
#define Y_MAX 1000000;
#define Y_MIN -1000000;
#define ALL_SIMBOLS "cossintanacosasinatansqrtlnlog()+-*/%^modx1234567890."

namespace Ui {
class Calculator;
class Deposit;
class Credits;
}  // namespace Ui

namespace s21 {

class View : public QObject {
  Q_OBJECT
 signals:
  void calculator_butt_ravnoClicked(QMap<QString, QString> &data);
  void credits_butt_ravnoClicked(QMap<QString, QString> &data);
  void deposit_butt_ravnoClicked(QMap<QString, QString> &data);

 private:
  Calculator *calculator;
  Deposit *deposit;
  Credits *credits;
 public slots:
  void handle_butt_go_to_deposClicked();
  void handle_butt_go_to_creditClicked();
  void handle_butt_go_to_calcClicked();
  void handle_calculator_butt_ravnoClicked();
  void handle_credits_butt_ravnoClicked();
  void handle_deposit_butt_ravnoClicked();
  void handle_res_q_hash_credits(const QHash<QString, double> &results);
  void handle_res_q_hash_deposit(const QHash<QString, double> &results);

 public:
  explicit View(QObject *parent = nullptr) : QObject(parent) {
    calculator = new Calculator();
    calculator->show();
    deposit = new Deposit();
    credits = new Credits();
    connect(calculator, &Calculator::butt_go_to_deposClicked, this,
            &View::handle_butt_go_to_deposClicked);
    connect(calculator, &Calculator::butt_go_to_creditClicked, this,
            &View::handle_butt_go_to_creditClicked);
    connect(credits, &Credits::butt_go_to_calcClicked, this,
            &View::handle_butt_go_to_calcClicked);
    connect(deposit, &Deposit::butt_go_to_calcClicked, this,
            &View::handle_butt_go_to_calcClicked);
    connect(calculator->get_butt_ravno(), &QPushButton::clicked, this,
            &View::handle_calculator_butt_ravnoClicked);
    connect(credits->get_butt_ravno(), &QPushButton::clicked, this,
            &View::handle_credits_butt_ravnoClicked);
    connect(deposit->get_butt_ravno(), &QPushButton::clicked, this,
            &View::handle_deposit_butt_ravnoClicked);
  };
  QMap<QString, QString> all_data_calculator();
  QMap<QString, QString> all_data_credits();
  QMap<QString, QString> all_data_deposit();
  void set_line_answer(const double text);

  void set_field_nachislenie_percents(const double text);
  void set_field_nalog_sum(const double text);
  void set_field_sum_at_the_end(const double text);

  void set_field_everymonth_payment(const double text);
  void set_field_pereplata(const double text);
  void set_field_all_priece(const double text);

  QCustomPlot *set_graph();

  void print_QMap(QMap<QString, QString> &dict);

  ~View() {
    delete calculator;
    delete deposit;
    delete credits;
  };
};
}  // namespace s21

#endif  // VIEW_H
