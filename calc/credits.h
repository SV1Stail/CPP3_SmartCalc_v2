#ifndef CREDITS_H
#define CREDITS_H

#include <qvariant.h>

#include <QApplication>
#include <QDebug>
#include <QDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QString>
#include <cmath>
#include <string>

#include "ui_credits.h"
namespace Ui {
class Credits;
}

class Credits : public QWidget {
  Q_OBJECT

 private:
  Ui::Credits *ui;

 public:
  explicit Credits(QWidget *parent = nullptr)
      : QWidget(parent), ui(new Ui::Credits) {
    ui->setupUi(this);
  };
  ~Credits() { delete ui; };
  QLineEdit *get_field_credit_sum();
  QLineEdit *get_field_percent();
  QLineEdit *get_field_srok();
  QRadioButton *get_radio_but_annu();
  QPushButton *get_butt_ravno();
  void set_field_everymonth_payment(const double text);
  void set_field_everymonth_payment(const QString &text);

  void set_field_pereplata(const double text);
  void set_field_all_priece(const double text);
 signals:
  void butt_go_to_calcClicked();
 private slots:
  void on_butt_exit_clicked() { QApplication::quit(); }
  void on_butt_go_to_calc_clicked() {
    emit butt_go_to_calcClicked();
    close();
  }
};

#endif  // CREDITS_H
