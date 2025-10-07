#include "../include/OccuranciesGetter.h"

OccuranciesGetter::OccuranciesGetter(const std::string &ourString,
                                     const std::string &subString) { // строка
  // и подстрока, в которых мы ищем число вхождений

  this->ourString = ourString; // cтрока
  this->subString = subString; // подстрока
}

int OccuranciesGetter::getCountOfOccurancies() { // функция поиска совпадения
  // строки и подстроки возвращает номер символа в строке, с которого есть
  // совподение
  if (stringModified) {     // проверяет переменную OccuranciesGetter
    getOccurancies();       // реализация функции
    stringModified = false; // изменяем функцию
  }
  return countOfOccurrences; // возвращает countOfOccurrences
}

void OccuranciesGetter::getOccurancies() { // возвращает количество вхождений
  // (OccuranciesGetter)
  countOfOccurrences = iterate(this, &OccuranciesGetter::getInclusion, 0,
                               0); // cоздаем ссылку на OccuranciesGetter
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
  while (pos != std::string::npos) {    // цикл нахождения количества вхождений,
                                        // возвращаемых функцией по указателю
    pos = (obj->*stepFunc)(value, pos); // вызов функции stepFunc у объекта
                                        // obj, результат поместить в pos
    if (pos != std::string::npos) {     // условие нахождения позиции по задаче,
                                        // которую решает функция по указателю
      ++value;                          // увеличиваем value
      ++pos;                            // увеличиваем pos
    }
  }
  return value; // выводим value
}

void OccuranciesGetter::setStrings(
    const std::string &ourString,
    const std::string &subString) { // строка и подстрока, в которых мы ищем
                                    // число вхождений
  this->ourString = ourString;      // cтрока
  this->subString = subString;      // подстрока
  stringModified = true;            // изменяем функцию
}
