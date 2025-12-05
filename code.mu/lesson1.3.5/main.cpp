#include <iostream>

void printMaxNumber(int *num1, int *num2) {
  if (num1 == num2) {
    std::cout << "Два числа являются одной переменной! Значение: " << *num1
              << '\n';
    return;
  }
  if (*num1 == *num2) {
    std::cout << "Два числа равны! Значение: " << *num1 << '\n';
    return;
  }
  std::cout << "Среди чисел " << *num1 << " и " << *num2 << " максимальное: ";
  if (*num1 > *num2) {
    std::cout << *num1 << '\n';
  } else {
    std::cout << *num2 << '\n';
  }
}

int main(int argc, char *argv[]) {
  int i = 36;
  int j = 12;
  printMaxNumber(&i, &j);
  return 0;
}
