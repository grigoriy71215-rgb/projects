#include "../include/VowelGetter.h" // библиотека данных для потока вывода
// VowelGetter
#include <algorithm>  // библиотека данных для потока вывода distance
#include <functional> // библиотека данных для потока вывода find_if
#include <iostream>   // библиотека данных для потока вывода cout
#include <string>     // библиотека данных для потока вывода string

std::string ourString = "Test test test"; // ввод строки
std::string vowels = "";                  // словарь гласных

/* Цель: заполнение словаря гласных пользователем
 * план функции:
 * */

void VowelGetter::getVowelsDictionary() {
  std::cout << "введите гласные: "; // ввод гласных пользователем
  std::cin >> vowels;
} /* Цель: определить, является ли знак гласной буквой. план функции: 1. если
     словарь пустой, вызвать функцию заполнения словаря пользователем 2. вернуть
     нахождение искомой буквы в строке гласных*/

bool VowelGetter::isVowel(char ch) { // определяет, является ли переданный
  // символ гласной буквой
  if (vowels.empty())      // проверяет является ли строка пустой
    getVowelsDictionary(); // вызов функции
  return vowels.find(ch) != std::string::npos; // проверяе содержится символ
  // ch в строке vowels
}

/* Цель: получить позицию по итератору план функции:
 * 1. возвратить std::distance от begin() и итератора в параметре*/
int VowelGetter::getPosByIterator(std::string::iterator stringIterator) {
  return std::distance(ourString.begin(), stringIterator); // вычисляет позицию
  // // в строке
}

/* Цель: получить итератор по позиции план функции:
1. возвратить сумму итератора, указываюшего на начало строки, и номера элемента
строки */
std::string::iterator VowelGetter::getIteratorByPos(int pos) {
  return ourString.begin() + pos;
}

/* Цель: получить позицию на следующую гласную план функции:
 * 1. из номера позиции получить итератор
 * 2.по начальному значению итератора найти итератор на первую гласную
 * 3. вернуть: 3.1. позицию по найденому итератору, если она не npos
 * 3.2. прикастовать npos к int в противном случае*/

int VowelGetter::getVowelInclusion(VowelGetter *obj, int value, int pos) {
  std::string::iterator ourStringPosIterator = getIteratorByPos(pos);
  std::string::iterator nextVowelIterator =
      std::find_if(ourStringPosIterator, ourString.end(),
                   [obj](char ch) { return obj->isVowel(ch); });
  if (nextVowelIterator >= ourString.end())
    return static_cast<int>(std::string::npos);
  else
    return getPosByIterator(nextVowelIterator);
}

/* Цель: функция высокого порядка для реализации способа подсчета того, что
     находит функция по указателю*/
int VowelGetter::iterate(std::function<int(VowelGetter *, int, int)> stepFunc,
                         int value, int pos) {
  while (pos != std::string::npos &&
         pos < static_cast<int>(ourString.length())) {
    pos = stepFunc(this, value, pos);
    if (pos != std::string::npos &&
        pos < static_cast<int>(ourString.length())) {
      ++value;
      std::cout << "Найдена гласная '" << ourString[pos] << "' на позиции "
                << pos << std::endl;
      ++pos;
    }
  }
  return value;
}
/*Цель: */

int VowelGetter::process() {
  if (vowels.empty()) {
    getVowelsDictionary();
  }
  auto boundFunc =
      std::bind(&VowelGetter::getVowelInclusion, this, std::placeholders::_1,
                std::placeholders::_2, std::placeholders::_3);
  int vowelCount = iterate(boundFunc, 0, 0);

  std::cout << "Всего найдено гласных: " << vowelCount << std::endl;
  return vowelCount;
}
