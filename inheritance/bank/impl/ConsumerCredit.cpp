#pragma once

#include "Credit.hpp" // библиотека данных для потока вывода сredit

class ConsumerCredit final : public Credit { // создать класс
public:                                      // публичные члены класса
  ConsumerCredit() : Credit("", 0) {} // конструктор по умолчанию, вызывает
  // credit
  ConsumerCredit(const std::string &clientName,
                 int creditSum)          // принимает
                                         // имя клиента и сумму кредита
      : Credit(clientName, creditSum) {} // принимает
  // имя клиента и сумму кредита
  ~ConsumerCredit() = default; // деструктор класса определенный как стандартный

  bool getCreditIssue() override { //
    if (creditSum < 10000) // проверяет если сумма кредита менше 10000, кредит
      // не одобрен
      return false; // возвращяет false, если сумма кредита менше 10000
    return true;    // возвращает true, если сумма кредита больше 10000
  }

  std::string getCreditName() const override { return "Consumer Credit"; }
};
