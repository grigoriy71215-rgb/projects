#include <algorithm>
#include <future>
#include <iostream>
#include <vector>

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

int getFutureByNum(int num) {
  auto future = std::async(std::launch::async, getRanks,
                           num); // auto = std::future<std::vector<int>>
  return *future.get().begin();
}

bool compareMainRanks(int num1, int num2) {
  return getFutureByNum(num1) == getFutureByNum(num2);
}

int main() {
  int num1 = 42;
  int num2 = 44;
  std::cout << "Первая цифра " << num1
            << (compareMainRanks(num1, num2) ? "" : " не")
            << " совпадает с первой цифрой " << num2 << '\n';
  return 0;
}
