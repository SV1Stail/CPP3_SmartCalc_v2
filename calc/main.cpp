#include <QApplication>
#include <locale>

#include "controller.h"
// #include "view.h"
int main(int argc, char *argv[]) {
  std::locale::global(std::locale("C"));
  QApplication a(argc, argv);
  //  s21::View w;
  s21::Controller controller;

  return a.exec();
}
