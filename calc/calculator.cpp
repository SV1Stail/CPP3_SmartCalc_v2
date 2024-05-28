#include "calculator.h"

#include "ui_calculator.h"

QLineEdit *Calculator::get_line_ask() { return ui->line_ask; }
QLineEdit *Calculator::get_line_x() { return ui->line_x; }
QLineEdit *Calculator::get_line_h() { return ui->line_h; }
QPushButton *Calculator::get_butt_ravno() { return ui->butt_ravno; }
void Calculator::set_line_answer(const double text) {
  ui->line_answer->setText(QString::number(text, 'f', 4));
}

QCustomPlot *Calculator::get_graph() { return ui->graph; }
