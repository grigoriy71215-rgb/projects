/* Задача: найти количество гласных в строке */
#include <algorithm>
#include <iostream>
#include <string>

std::string ourString = "Test test test"; // ввод строки
std::string vowels = "";                  // словарь гласных

/* Цель: заполнение словаря гласных пользователем
 * план функции:
 * */

void getVowelsDictionary() {
  std::cout << "введите гласные: ";
  std::cin >> vowels;
}

/* Цель: определить, является ли знак гласной буквой.
 * план функции:
 * 1. если словарь пустой, вызвать функцию заполнения словаря пользователем
 * 2. вернуть нахождение искомой буквы в строке гласных*/
bool isVowel(char ch) {
  if (vowels.empty())
    getVowelsDictionary();
  return vowels.find(ch) != std::string::npos;
}

/* Цель: получить позицию по итератору
 * план функции:
 * 1. возвратить std::distance от begin() и итератора в параметре*/

int getPosByIterator(std::string::iterator stringIterator) {
  return std::distance(ourString.begin(), stringIterator);
}

/* Цель: получить итератор по позиции
 * план функции:
 * 1. возвратить сумму итератора, указываюшего на начало строки, и номера
 * элемента строки */

std::string::iterator getIteratorByPos(int pos) {
  return ourString.begin() + pos;
}

/* Цель: получить позицию на следующую гласную
 * план функции:
 * 1. из номера позиции получить итератор
 * 2. по начальному значению итератора найти итератор на первую гласную
 * 3. вернуть:
 * 3.1. позицию по найденому итератору, если она не npos
 * 3.2. прикастовать npos к int в противном случае*/
int getVowelInclusion(int value, int pos) {
  std::string::iterator ourStringPosIterator = getIteratorByPos(pos);
  std::string::iterator nextVowelIterator =
      std::find_if(ourStringPosIterator, ourString.end(), isVowel);
  if (nextVowelIterator >= ourString.end())
    return static_cast<int>(std::string::npos);
  else
    return getPosByIterator(nextVowelIterator);
}

/* Цель: функция высокого порядка для реализации способа подсчета того,
 * что находит функция по указателю*/

int iterate(int (*stepFunc)(int, int), int value,
            int pos) { // функция высокого
  // порядка (в параметрах есть указатель на функцию) для реализации способа
  // подсчета того, что находит функция по указателю
  while (pos != std::string::npos) { // цикл нахождения количества вхождений,
    // возвращаемых функцией по указателю
    pos = stepFunc(value, pos);
    if (pos != std::string::npos) { // условие нахождения позиции по задаче,
      // которую решает функция по указателю
      ++value;
      ++pos;
    }
  }
  return value;
}

int main(int argc, char *argv[]) {
  std::cout << iterate(getVowelInclusion, 0, 0)
            << '\n'; // вызов функции нахождения
  // количества гласных в строке
  return 0;
}
