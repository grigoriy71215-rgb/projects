#include <algorithm>
#include <iostream>
#include <string>

int getNextRank(int &number) {
  int remainder = number % 10;
  number /= 10;
  return remainder;
}

void addRankToString(std::string &str, int &rank) { str += (char)rank + 48; }

void addAllRanksToString(std::string &str, int number) {
  while (number != 0) {
    int rank = getNextRank(number);
    addRankToString(str, rank);
  }
  std::reverse(str.begin(), str.end());
}

int main() {
  std::string res;
  int number = 183247;
  addAllRanksToString(res, number);
  std::cout << "Integer: " << number << "; String: \"" << res << "\"\n";
}
