#pragma once

#include <string> // библиотека данных для потока вывода string

// RAII - Resource Acquisition is initialization - захват ресурса - это
// инициализация
class Credit {       // cоздать базовый класс Credit
  Credit() = delete; // удаление конструктора по умалчянию

protected:
  std::string clientName; // объявление члена касса
  int creditSum;          // член класса который хранит сумму кредита

public: // публичные члены класса
  virtual ~Credit() =
      default; // обьявление деструктора с реализацией по умалчянию
  Credit(const std::string &clientName, int creditSum)
      : clientName(clientName), creditSum(creditSum) {
  } // конструктор который принимает реальные данные

  // Чисто виртуальные методы (для переопределения в дочерних классах)
  virtual bool getCreditIssue() = 0; // обязывает все конкреттные типы кредита
  // функция для отображения названия кредита
  virtual std::string getCreditName() const = 0;
};
