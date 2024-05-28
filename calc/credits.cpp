#include "credits.h"

#include "ui_credits.h"

QLineEdit *Credits::get_field_credit_sum() { return ui->field_credit_sum; }
QLineEdit *Credits::get_field_percent() { return ui->field_percent; }
QLineEdit *Credits::get_field_srok() { return ui->field_srok; }
QRadioButton *Credits::get_radio_but_annu() { return ui->radio_but_annu; }
QPushButton *Credits::get_butt_ravno() { return ui->butt_ravno; }
void Credits::set_field_everymonth_payment(const double text) {
  ui->field_everymonth_payment->setText(QString::number(text, 'f', 2));
}
void Credits::set_field_everymonth_payment(const QString &text) {
  ui->field_everymonth_payment->setText(text);
}
void Credits::set_field_pereplata(const double text) {
  ui->field_pereplata->setText(QString::number(text, 'f', 2));
}
void Credits::set_field_all_priece(const double text) {
  ui->field_all_priece->setText(QString::number(text, 'f', 2));
}
