#include "IntegerOperations.h"

int IntegerOperations::getLeastRank(int &num) {
  int remainder = num % 10;
  num /= 10;
  return remainder;
}
