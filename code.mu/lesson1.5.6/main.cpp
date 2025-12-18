#include <iostream>

int greater(int num1, int num2, int num3) {
  return num1 > num2 ? (num1 > num3 ? num1 : num3)
                     : (num2 > num3 ? num2 : num3);
}

int smaller(int num1, int num2, int num3) {
  return num1 < num2 ? (num1 < num3 ? num1 : num3)
                     : (num2 < num3 ? num2 : num3);
}

int input(int num1, int num2, int num3) {
  std::cout << "Введите первое число: " << '\n';
  std::cin >> num1;
  std::cout << "Введите второе число: " << '\n';
  std::cin >> num2;
  std::cout << "Введите третье число: " << '\n';
  std::cin >> num3;
  return 0;
}

int main() {}
