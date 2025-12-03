#include <iostream>

// void deleteByTen(int &num) { // отсечь младший разряд
// num /= 10;
// }

int getCountOfRanks(int &num) { // получить подсчет разрядов
  int res = 0;
  std::cout << "9: " << num << '\n';
  while (num != 0) {
    std::cout << "11: " << num << '\n';
    std::cout << "13: " << num << '\n';
    ++res;
    std::cout << "15: " << num << '\n';
  }
  std::cout << "17: " << num << '\n';
  return res;
}

int main(int argc, char *argv[]) {
  int i = 897;
  std::cout << getCountOfRanks(i) << '\n';
  return 0;
}
