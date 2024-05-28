#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <qvariant.h>

#include <QApplication>
#include <QDate>
#include <QDateEdit>
#include <QDateTime>
#include <QDebug>
#include <QDialog>
#include <QString>
#include <cmath>
#include <ctime>
#include <string>

#include "ui_deposit.h"
namespace Ui {
class Deposit;
}

class Deposit : public QWidget {
  Q_OBJECT

 private:
  Ui::Deposit *ui;

 public:
  explicit Deposit(QWidget *parent = nullptr)
      : QWidget(parent), ui(new Ui::Deposit) {
    ui->setupUi(this);
  };
  ~Deposit() { delete ui; };
  QLineEdit *get_field_deposit_sum();
  QLineEdit *get_field_srok();
  QLineEdit *get_field_percent();
  QLineEdit *get_field_nalog();
  QRadioButton *get_radio_kapitalizacia();
  QPushButton *get_butt_ravno();
  void set_field_nachislenie_percents(const double text);
  void set_field_nalog_sum(const double text);
  void set_field_sum_at_the_end(const double text);
  void spisok_popolneniy(int srok);
 signals:
  void butt_go_to_calcClicked();
 private slots:
  void on_butt_exit_clicked() { QApplication::quit(); }
  void on_butt_g_to_calc_clicked() {
    emit butt_go_to_calcClicked();
    close();
  }
};

#endif  // DEPOSIT_H
