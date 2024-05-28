#include "deposit.h"

#include "ui_deposit.h"

QLineEdit *Deposit::get_field_deposit_sum() { return ui->field_deposit_sum; }
QLineEdit *Deposit::get_field_srok() { return ui->field_srok; }
QLineEdit *Deposit::get_field_percent() { return ui->field_percent; }
QLineEdit *Deposit::get_field_nalog() { return ui->field_nalog; }

QRadioButton *Deposit::get_radio_kapitalizacia() {
  return ui->radio_kapitalizacia;
}
QPushButton *Deposit::get_butt_ravno() { return ui->butt_ravno; }
void Deposit::set_field_nachislenie_percents(const double text) {
  ui->field_nachislenie_percents->setText(QString::number(text, 'f', 2));
}
void Deposit::set_field_nalog_sum(const double text) {
  ui->field_nalog_sum->setText(QString::number(text, 'f', 2));
}
void Deposit::set_field_sum_at_the_end(const double text) {
  ui->field_sum_at_the_end->setText(QString::number(text, 'f', 2));
}
void Deposit::spisok_popolneniy(int srok) {
  //   ui->dateEdit->setDate(QDate::currentDate());
  ui->dateEdit->setMinimumDate(QDate(1900, 1, 1));
  ui->dateEdit->setMaximumDate(QDate(2100, 12, 31));
  QDate selectedDate = ui->dateEdit->date();
  QDateTime dateTime(selectedDate);
  time_t t = dateTime.toTime_t();

  //  time_t t1 = time(NULL);
  tm time_now = *localtime(&t);
  int counter_mon = 1, year = 0;
  QString date_all_qstring;
  ui->lsit_snytia->clear();
  if (ui->radio_pays_from_bank->isChecked()) {
    for (int i = 1; i <= srok; i++) {
      int month_int = time_now.tm_mon + counter_mon + 1;  // январь = 0
      if (month_int > 12) {
        month_int -= 12;
        counter_mon -= 12;
        year++;
      }
      counter_mon++;
      QString month_qstring = QString::number(month_int),
              day_qstring = QString::number(time_now.tm_mday),
              year_qstring = QString::number(time_now.tm_year + 1900 + year);
      date_all_qstring = day_qstring + "." + month_qstring + "." + year_qstring;
      ui->lsit_snytia->addItem(date_all_qstring);
    }
  } else {
    for (int i = 1; i <= srok; i++) {
      int month_int = time_now.tm_mon + counter_mon + 1;  // январь = 0
      if (month_int > 12) {
        month_int -= 12;
        counter_mon -= 12;
        year++;
      }
      counter_mon++;
      QString month_qstring = QString::number(month_int),
              day_qstring = QString::number(time_now.tm_mday),
              year_qstring = QString::number(time_now.tm_year + 1900 + year);
      date_all_qstring = day_qstring + "." + month_qstring + "." + year_qstring;
    }
    ui->lsit_snytia->addItem(date_all_qstring);
  }
  //    ui->lsit_popolneniya->clear();
  int month_int = time_now.tm_mon + 1;
  QString month_qstring = QString::number(month_int),
          day_qstring = QString::number(time_now.tm_mday),
          year_qstring = QString::number(time_now.tm_year + 1900);
  date_all_qstring = day_qstring + "." + month_qstring + "." + year_qstring;
  ui->lsit_popolneniya->addItem(date_all_qstring);
}
