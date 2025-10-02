#include <iostream>

int getRemainder(int divisible, int divider) { // divisible - делимое, divider - делитель
  int remainder = 0; // остаток от деления
  int multiplier = 0; // результат деления
  do {
    ++multiplier;
  } while (divisible - multiplier * divider > divider); // условие проверки: делимое - результат деления * делитель (остаток от деления) > делитель
  remainder = divisible - multiplier * divider; // получение остатка от деления при максимальном результате деления
  return remainder; // вывод остатка от деления
}

int main (int argc, char *argv[]) {
  std::cout << getRemainder(17, 3) << '\n';  
  return 0;
}
