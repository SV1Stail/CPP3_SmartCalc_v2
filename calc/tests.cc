#include "gtest/gtest.h"
#include "model.h"

class CalculatorTests : public ::testing::Test {
 protected:
  s21::Model model;  // Тестовый объект

  // Можно добавить методы SetUp() и TearDown(), если необходима предварительная
  // настройка/очистка
};

// Тест на сложение

TEST_F(CalculatorTests, MainCalculation1) {
  std::string str = "3+x";
  EXPECT_EQ(3, model.MainCalculation(str, 0));
}
TEST_F(CalculatorTests, MainCalculation2) {
  std::string str = "sqrt(x) + sin(1) - x^2";
  double x = 1;
  EXPECT_EQ(sqrt(x) + sin(1) - x * x, model.MainCalculation(str, x));
}
TEST_F(CalculatorTests, MainCalculation3) {
  std::string str = "(cos(1) - tan(x))";
  double epsilon = 0.00001;
  double x = 1;
  EXPECT_NEAR((cos(1) - tan(x)), model.MainCalculation(str, x), epsilon);
}
TEST_F(CalculatorTests, MainCalculation4) {
  std::string str = "acos(x) / asin(x)";
  double epsilon = 0.00001;
  double x = 1;
  EXPECT_NEAR(acos(x) / asin(x), model.MainCalculation(str, x), epsilon);
}
TEST_F(CalculatorTests, MainCalculation5) {
  std::string str = "atan(x) * ln(x)";
  double epsilon = 0.00001;
  double x = 1;
  EXPECT_NEAR(acos(x) / asin(x), model.MainCalculation(str, x), epsilon);
}

TEST_F(CalculatorTests, MainCalculation6) {
  std::string str = "x*x*x mod x";
  double epsilon = 0.00001;
  double x = 1;
  EXPECT_NEAR(fmod(x * x * x, x), model.MainCalculation(str, x), epsilon);
}
TEST_F(CalculatorTests, MainCalculation7) {
  std::string str =
      "atan(x) - 3 * (4 - 2) + (cos(1) - tan(x)) + acos(x) / asin(x)";
  double epsilon = 0.00001;
  double x = 1;
  EXPECT_NEAR(atan(x) - 3 * (4 - 2) + (cos(1) - tan(x)) + acos(x) / asin(x),
              model.MainCalculation(str, x), epsilon);
}

TEST_F(CalculatorTests, MainCreditAnnuTest) {
  double credit_sum = 100000;  // Примерная сумма кредита
  double percent = 10;         // Процентная ставка
  double srok = 12;            // Срок кредита в месяцах
  auto result = model.main_credit_annu(credit_sum, percent, srok);
  // Проверьте ожидаемые значения в result, например:
  EXPECT_NEAR(result["field_everymonth_payment"], 8791.59,
              0.01);  // Ожидаемое значение ежемесячного платежа
  EXPECT_NEAR(result["field_pereplata"], 5499,
              1);  // Ожидаемое значение ежемесячного платежа
  EXPECT_NEAR(result["field_all_priece"], 105499,
              1);  // Ожидаемое значение ежемесячного платежа
}
TEST_F(CalculatorTests, MainCreditdiffTest) {
  double credit_sum = 100000;  // Примерная сумма кредита
  double percent = 10;         // Процентная ставка
  double srok = 12;            // Срок кредита в месяцах
  auto result = model.main_credit_diff(credit_sum, percent, srok);
  // Проверьте ожидаемые значения в result, например:
  EXPECT_NEAR(result["every_month_payment_diff_max"], 9182,
              1);  // Ожидаемое значение ежемесячного платежа
  EXPECT_NEAR(result["every_month_payment_diff_min"], 8333.59,
              1);  // Ожидаемое значение ежемесячного платежа
  EXPECT_NEAR(result["field_pereplata"], 5187,
              1);  // Ожидаемое значение ежемесячного платежа
  EXPECT_NEAR(result["field_all_priece"], 105187,
              1);  // Ожидаемое значение ежемесячного платежа
}
TEST_F(CalculatorTests, main_deposit_back_pays_every_month) {
  double credit_sum = 100000;  // Примерная сумма кредита
  double percent = 10;         // Процентная ставка
  double srok = 12;            // Срок кредита в месяцах
  double nalog = 13;
  auto result = model.main_deposit_back_pays_every_month(credit_sum, percent,
                                                         srok, nalog);
  // Проверьте ожидаемые значения в result, например:
  EXPECT_NEAR(result["field_nachislenie_percents"], 9863,
              1);  // Ожидаемое значение ежемесячного платежа
  EXPECT_NEAR(result["field_nalog_sum"], 1282,
              1);  // Ожидаемое значение ежемесячного платежа
  EXPECT_NEAR(result["field_sum_at_the_end"], 108580,
              1);  // Ожидаемое значение ежемесячного платежа
}
TEST_F(CalculatorTests, main_deposit_kapitalizacia) {
  double credit_sum = 100000;  // Примерная сумма кредита
  double percent = 10;         // Процентная ставка
  double srok = 12;            // Срок кредита в месяцах
  double nalog = 13;
  auto result =
      model.main_deposit_kapitalizacia(credit_sum, percent, srok, nalog);
  // Проверьте ожидаемые значения в result, например:
  EXPECT_NEAR(result["field_nachislenie_percents"], 10471,
              1);  // Ожидаемое значение ежемесячного платежа
  EXPECT_NEAR(result["field_nalog_sum"], 1361,
              1);  // Ожидаемое значение ежемесячного платежа
  EXPECT_NEAR(result["field_sum_at_the_end"], 109110,
              1);  // Ожидаемое значение ежемесячного платежа
}

// Точка входа для Google Test
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
