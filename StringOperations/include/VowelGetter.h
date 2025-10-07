#pragma once
#include <string>

class VowelGetter {
private:                                // скрытые члены класса
  int getInclusion(int value, int pos); // функция поиска совпадения строки и
  // подстроки возвращает номер символа в строке, с которого есть совподение
  int iterate(VowelGetter *obj, int (VowelGetter::*stepFunc)(int, int),
              int value,
              int pos); // функция высокого
  // порядка (в параметрах есть указатель на функцию) для реализации способа
  // подсчета того, что находит функция по указателю
  void getOccurancies(); // вызов функции iterate с параметром getInclusion

  std::string ourString; // строка, в которой мы ищем число вхождений подстроки
  std::string subString; // подстрока
  int countOfOccurrences = 0;
  bool stringModified = true;

public:
  VowelGetter(); // конструктор по умолчанию
  VowelGetter(
      const std::string &ourString,
      const std::string &subString); // конструктор с пользовательскими
                                     // параметрами (задает строку и подстроку)
  ~VowelGetter() = default;          // деструктор

  int getCountOfOccurancies(); // пользовательская логика вызова подсчета
  void setStrings(const std::string &ourString, const std::string &subString);
};
