#include <iostream>

bool isPositive(int num) { return num > 0; }

void getNextPowerOfTwo(int &prevPower) { prevPower *= 2; }

int main(int argc, char *argv[]) {
  int lastPower = 0;
  std::cout << "Введите степень двойки: ";
  std::cin >> lastPower;
  int prevPower = 1;
  std::cout << "Перые " << lastPower << " степеней двойки равны:\n";
  for (int i = 0; i < lastPower; ++i) {
    std::cout << i << "-ая степень: " << prevPower << '\n';
    getNextPowerOfTwo(prevPower);
  }
  return 0;
}
