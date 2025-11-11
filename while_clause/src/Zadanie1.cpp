#include "Zadanie1.h"
#include <utility>

int Zadanie1::getCountOfRanks(int &&digit) {
  int counter = 0;
  while (digit != 0) {
    cutLeastRank(std::move(digit));
    ++counter;
  }
  return counter;
}

void Zadanie1::cutLeastRank(int &&digit) { digit /= 10; }
