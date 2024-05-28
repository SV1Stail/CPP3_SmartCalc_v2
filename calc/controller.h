#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QVector>
#include <QWidget>

#include "model.h"
#include "view.h"

namespace s21 {
class View;
class Model;
class Controller : public QObject {
  Q_OBJECT
 signals:
  void res_q_hash_credits(const QHash<QString, double> &results);
  void res_q_hash_deposit(const QHash<QString, double> &results);

 private:
  View *view;
  Model *model;

 public:
  explicit Controller(QObject *parent = nullptr) : QObject(parent) {
    view = new View();
    model = new Model();
    connect(view, &View::calculator_butt_ravnoClicked, this,
            &Controller::main_calculator);
    connect(view, &View::credits_butt_ravnoClicked, this,
            &Controller::main_credits);
    connect(view, &View::deposit_butt_ravnoClicked, this,
            &Controller::main_deposit);
    connect(this, &Controller::res_q_hash_credits, view,
            &View::handle_res_q_hash_credits);
    connect(this, &Controller::res_q_hash_deposit, view,
            &View::handle_res_q_hash_deposit);
  }

  bool check_line_ask_for_ALL_SIMBOLS(QString line);
  bool check_line_is_int(const QString &str);
  bool check_line_is_double(const QString &str);
  void main_calculator(QMap<QString, QString> &dict);
  void main_credits(QMap<QString, QString> &dict);
  void main_deposit(QMap<QString, QString> &dict);

  void print_QMap(QMap<QString, QString> &dict) {
    QMapIterator<QString, QString> i(dict);
    while (i.hasNext()) {
      i.next();
      qDebug() << i.key() << ": " << i.value();
    }
    qDebug() << endl;
  }
};

}  // namespace s21
#endif  // CONTROLLER_H
