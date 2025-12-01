#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int getLeastRank(int &num) {
  int remainder = num % 10;
  num /= 10;
  return remainder;
}

std::vector<int> getRankVector(int &num) {
  std::vector<int> rankVector;
  while (num != 0) {
    rankVector.push_back(getLeastRank(num));
  }
  std::reverse(rankVector.begin(), rankVector.end());
  return rankVector;
}

std::string getString(int &num) {
  std::vector<int> rankVector = getRankVector(num);
  std::string result;
  std::for_each(rankVector.cbegin(), rankVector.cend(),
                [&](int a) { result += (char)(a + 48); });
  return result;
}

std::string getStringAlt(int &num) { return std::to_string(num); }

int main(int argc, char *argv[]) {
  int i = 123;
  // std::cout << getString(i) << '\n';
  std::cout << getStringAlt(i) << '\n';
  return 0;
}
