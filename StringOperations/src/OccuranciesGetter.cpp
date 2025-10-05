#include "../include/OccuranciesGetter.h"
#include <iostream>

OccuranciesGetter::OccuranciesGetter(const std::string &ourString,
                                     const std::string &subString) {
  this->ourString = ourString;
  this->subString = subString;
}

int OccuranciesGetter::getCountOfOccurancies() {
  if (stringModified) {
    getOccurancies();
    stringModified = false;
  }
  return countOfOccurrences;
}

void OccuranciesGetter::getOccurancies() {
  countOfOccurrences = iterate(this, &OccuranciesGetter::getInclusion, 0, 0);
}

int OccuranciesGetter::getInclusion(
    int value, int pos) { // функция поиска совпадения строки и
  // подстроки возвращает номер символа в строке, с которого есть совподение
  return ourString.find(subString, pos);
}

int OccuranciesGetter::iterate(OccuranciesGetter *obj,
                               int (OccuranciesGetter::*stepFunc)(int, int),
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

void OccuranciesGetter::setStrings(const std::string &ourString,
                                   const std::string &subString) {
  this->ourString = ourString;
  this->subString = subString;
  stringModified = true;
}
