/*
 * 1. Вывод чисел: Напишите программу, которая выводит на экран все целые числа
 * от 1 до 100.
 * 2. Четные числа: Выведите все четные числа в диапазоне от 2 до 50.
 * 3. Сумма чисел: Посчитайте и выведите сумму всех целых чисел от 1 до N (N
 * вводит пользователь).
 * 4. Факториал: Вычислите и выведите факториал числа N (N! = 1 * 2 * 3 * ... *
 * N). Учесть, что 0! = 1.
 */

#include <iostream>
#include <limits>
#include <utilities/CinFeatures.h>

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

void zadanie3() {
  int N, sum = 0;
  std::cout << "Введите N: ";
  std::cin >> N;
  for (int i = 1; i <= N; i++) {
    sum += i;
  }
  std::cout << "Сумма чисел от 1 до " << N << " = " << sum << '\n';
}

// Факториал числа N - это произведение всех чисел от 1 до N

void zadanie4() {
  int N = 1;
  int mul = 1;
  std::cout << "N: " << N << '\n';
  std::cout << "Введите число для нахождения факториала: ";
  std::cin >> N;
  while (std::cin.fail()) {
    N = 0;
    std::cout << "Ошибка ввода: введено не число!\n";
    std::cout << "Введите число для нахождения факториала: ";
    CinFeatures::clear();
    S std::cin >> N;
  }
  for (int i = 1; i <= N; i++) {
    mul *= i;
  }
  std::cout << "Факториал числа " << N << " = " << mul << '\n';
}

int main(int argc, char *argv[]) {
  // std::cout << "Задание 1:\n";
  // zadanie1();
  // std::cout << "Задание 2:\n";
  // zadanie2();
  // std::cout << "задание 3:\n";
  // zadanie3();
  std::cout << "задание 4:\n";
  zadanie4();
  return 0;
}
