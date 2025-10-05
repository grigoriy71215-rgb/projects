#pragma once

#include <string> // библиотека данных для потока вывода std::string

class OccuranciesGetter {               // создаем класс
private:                                // скрытые члены класса
  int getInclusion(int value, int pos); // функция поиска совпадения строки и
  // подстроки возвращает номер символа в строке, с которого есть совподение
  int iterate(OccuranciesGetter *obj,
              int (OccuranciesGetter::*stepFunc)(int, int), int value,
              int pos); // функция высокого
  // порядка (в параметрах есть указатель на функцию) для реализации способа
  // подсчета того, что находит функция по указателю
  void getOccurancies(); // вызов функции iterate с параметром getInclusion

  std::string ourString; // строка, в которой мы ищем число вхождений подстроки
  std::string subString; // подстрока
  int countOfOccurrences = 0;
  bool stringModified = true;

public:
  OccuranciesGetter(); // конструктор по умолчанию
  OccuranciesGetter(
      const std::string &ourString,
      const std::string &subString); // конструктор с пользовательскими
                                     // параметрами (задает строку и подстроку)
  ~OccuranciesGetter() = default;    // деструктор

  int getCountOfOccurancies(); // пользовательская логика вызова подсчета
  void setStrings(const std::string &ourString, const std::string &subString);
};
