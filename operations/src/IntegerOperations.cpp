#include "IntegerOperations.h"

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
