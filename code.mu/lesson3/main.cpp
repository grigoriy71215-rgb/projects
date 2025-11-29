// int - тип целых чисел
// char - для одной буквы
// void - пустой тип
// double - большие числа с плавующей точкой
// bool - логический тип
// float - малые числа с плавующей точкой
// std::string - для хронения строк
// std::vector - массив

#include <iostream>
#include <string>

char getLastChar(const std::string &line) { return *--line.end(); }

int main(int argc, char *argv[]) {
  std::cout << getLastChar("string") << '\n';
  return 0;
}
