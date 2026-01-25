#include "IntegerOperations.h"
#include <algorithm>

int IntegerOperations::getLeastRank(int &num) {
  int remainder = num % 10;
  num /= 10;
  return remainder;
}

void IntegerOperations::moveLeastRankFromSourceToDest(int &source, int &dest) {
  dest *= 10;
  dest += IntegerOperations::getLeastRank(source);
}

int IntegerOperations::reverse(int source) {
  int dest = 0;
  while (source != 0) {
    moveLeastRankFromSourceToDest(source, dest);
  }
  return dest;
}

std::vector<int> IntegerOperations::getRanks(int number) {
  std::vector<int> result;
  while (number != 0) {
    result.push_back(getNextRank(number));
  }
  std::reverse(result.begin(), result.end());
  return result;
}

int IntegerOperations::getNextRank(int &number) {
  int remainder = number % 10;
  number /= 10;
  return remainder;
}
