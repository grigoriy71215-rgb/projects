#include <iostream>
#include <vector>

bool chekEven(const int &num) { return num % 2 == 0; }

int getNextRank(int &number) {
  int remainder = number % 10;
  number /= 10;
  return remainder;
}

std::vector<int> getRanks(int number) {
  std::vector<int> result;
  while (number != 0) {
    result.push_back(getNextRank(number));
  }
  std::reverse(result.begin(), result.end());
  return result;
}

int getEven(const int &num) {
  int sum = 0;
  for (auto i : getRanks(num)) {
    if (i % 2 == 0)
      sum += i;
  }
  return sum;
}

int main(int argc, char *argv[]) {
  int num = 12395;
  std::cout << "Сумма всех четных цифр числа " << num << " равна "
            << getEven(num) << '\n';
  return 0;
}
