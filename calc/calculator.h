#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <qvariant.h>
#include <qvector.h>

#include <QApplication>
#include <QDebug>
#include <QDialog>
#include <QString>
#include <cstring>

#include "qcustomplot.h"
#include "ui_calculator.h"
namespace Ui {
class Calculator;
}

class Calculator : public QWidget {
  Q_OBJECT

 private:
  Ui::Calculator *ui;

 public:
  explicit Calculator(QWidget *parent = nullptr)
      : QWidget(parent), ui(new Ui::Calculator) {
    ui->setupUi(this);
  };
  ~Calculator() { delete ui; };
  QCustomPlot *get_graph();
  QLineEdit *get_line_ask();
  QLineEdit *get_line_x();
  QLineEdit *get_line_h();
  QPushButton *get_butt_ravno();
  void set_line_answer(const double text);
 signals:
  void butt_go_to_deposClicked();
  void butt_go_to_creditClicked();
 private slots:
  void on_butt_exit_clicked() { QApplication::quit(); }
  void on_butt_go_to_depos_clicked() {
    emit butt_go_to_deposClicked();
    close();
  }
  void on_butt_go_to_credit_clicked() {
    emit butt_go_to_creditClicked();
    close();
  }
};

#endif  // CALCULATOR_H
