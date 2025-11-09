/*
 * 1. Вывод чисел: Напишите программу, которая выводит на экран все целые числа
 * от 1 до 100.
 * 2. Четные числа: Выведите все четные числа в диапазоне от 2 до 50.
 */

#include <iostream>

void zadanie1() {
  for (int i = 1; i <= 100; i++) {
    std::cout << i << " ";
  }
  std::cout << '\n';
}

inline bool isEven(const int &number) { return number % 2 == 0; }

void zadanie2() {
  for (int i = 2; i <= 50; i++) {
    if (isEven(i))
      std::cout << i << " ";
  }
  std::cout << '\n';
}

int main(int argc, char *argv[]) {
  zadanie1();
  zadanie2();
  return 0;
}
