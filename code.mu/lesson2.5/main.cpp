#include <iostream>
#include <unordered_map>

std::unordered_map<int, int> factorials;

int findFactorial(unsigned int num) {
  auto it = factorials.find(num);
  if (it != factorials.end())
    return it->second;
  if (num == 0 || num == 1)
    return 1;
  else {
    int value = num * findFactorial(num - 1);
    factorials[num] = value;
    return value;
  }
}

int main(int argc, char *argv[]) {
  unsigned int num = 12;
  std::cout << "Факториал числа " << num << " : " << findFactorial(num) << '\n';
  std::cout << "Количество элементов в factorials: " << factorials.size()
            << '\n';
  std::cout << "Оверхед по памяти: " << sizeof(factorials) << '\n';
  return 0;
}
