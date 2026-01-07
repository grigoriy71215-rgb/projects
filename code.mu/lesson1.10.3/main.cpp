#include <iostream>
#include <operations/IntegerOperations.h>

// source - источник (переменная, с которой берем разряды,
// dest - приемник (переменная, в которую добавляем разряд))
void moveLeastRankFromSourceToDest(int &source, int &dest) {
  dest *= 10;
  dest += IntegerOperations::getLeastRank(source);
}

int moveAllRanks(int source) {
  int dest = 0;
  while (source != 0) {
    moveLeastRankFromSourceToDest(source, dest);
  }
  return dest;
}

int main(int argc, char *argv[]) {
  int i = 1234567;
  std::cout << "Число " << i << " наоборот: " << moveAllRanks(i) << '\n';
  return 0;
}
