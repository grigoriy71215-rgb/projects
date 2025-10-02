/* Задача: найти в строке число вхождений другой подстроки, введенной
 * пользователем */

#include <iostream>
#include <string>

std::string ourString = "Test test test"; // ввод строки
std::string subString = "test";           // ввод под строки

int getInclusion(int value, int pos) { // функция поиска совпадения строки и
  // подстроки возвращает номер символа в строке, с которого есть совподение
  return ourString.find(subString, pos);
}

int iterate(int (*stepFunc)(int, int), int value, int pos) { // функция высокого
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
  std::cout << iterate(getInclusion, 0, 0) << '\n'; // вызов функции нахождения
  // числа вхождений подстроки в стрку
  return 0;
}
