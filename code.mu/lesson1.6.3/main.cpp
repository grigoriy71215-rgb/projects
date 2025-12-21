#include <initializer_list>
#include <iostream>
#include <stdexcept>

// @throws invalid_argument exception
int getIntFromChar(char ch) {
  if (ch < 48 || ch > 57)
    throw std::invalid_argument("ch is not a digit.");
  return ch - 48;
}

// возвращает -1 если в chil есть хотя бы 1 не цифра
int sum(std::initializer_list<char> chil) {
  int result = 0;
  for (auto ch : chil) {
    try {
      result += getIntFromChar(ch);
    } catch (std::invalid_argument ia) {
      std::cout << "Cause: " << ia.what() << '\n';
      return -1;
    }
  }
  return result;
}

int main(int argc, char *argv[]) {
  char chr1 = 'a';
  char chr2 = '2';
  char chr3 = '3';
  int res = sum({chr1, chr2, chr3});
  if (res != -1)
    std::cout << "Сумма цифр " << chr1 << " + " << chr2 << " + " << chr3
              << " равна " << res << '\n';
  else
    std::cout << "В символах " << chr1 << ", " << chr2 << ", " << chr3
              << " есть не цифры!\n";
  return 0;
}
