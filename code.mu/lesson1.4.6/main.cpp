#include <algorithm>
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

bool hasTwoDigits(const std::vector<int> &ranks) { return ranks.size() == 2; }

bool compareLeastAndMainRank(const std::vector<int> &ranks) {
  return *ranks.begin() <= *(--ranks.end());
}

int main(int argc, char *argv[]) {
  int i = 12;
  std::vector<int> ranks = getRanks(i);
  if (hasTwoDigits(ranks)) {
    std::cout << "Второй элемент двузначного числа " << i
              << (!compareLeastAndMainRank(ranks) ? " меньше или равен"
                                                  : " больше")
              << ", чем первый элемент\n";
  } else {
    std::cout << "Число " << i << " не является двузначным!\n";
  }
  return 0;
}
