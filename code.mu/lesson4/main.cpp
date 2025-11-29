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

bool checkFirstChar(const std::string &line1, const std::string &line2) {
  return *line1.begin() == *line2.begin();
}

int main(int argc, char *argv[]) {
  std::cout << checkFirstChar("string1", "string2") << '\n';
  return 0;
}
