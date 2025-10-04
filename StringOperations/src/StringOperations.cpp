#include "../include/StringOperations.h"

StringOperations::StringOperations(const std::string &ourString,
                                   const std::string &subString) {
  this->ourString = ourString;
  this->subString = subString;
}

int StringOperations::getCountOfOccurrences() {
  return iterate(this, &StringOperations::getInclusion, 0, 0);
}

int StringOperations::getInclusion(
    int value, int pos) { // функция поиска совпадения строки и
  // подстроки возвращает номер символа в строке, с которого есть совподение
  return ourString.find(subString, pos);
}

int StringOperations::iterate(StringOperations *obj,
                              int (StringOperations::*stepFunc)(int, int),
                              int value,
                              int pos) { // функция высокого
  // порядка (в параметрах есть указатель на функцию) для реализации способа
  // подсчета того, что находит функция по указателю
  while (pos != std::string::npos) { // цикл нахождения количества вхождений,
                                     // возвращаемых функцией по указателю
    pos = (obj->*stepFunc)(value, pos);
    if (pos != std::string::npos) { // условие нахождения позиции по задаче,
      // которую решает функция по указателю
      ++value;
      ++pos;
    }
  }
  return value;
}
