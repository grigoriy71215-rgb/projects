#include <iostream>
#include <operations/IntegerOperations.h>
#include <vector>

int getSumRanks(const std::vector<int> &ranks) {
  return ranks.front() + ranks.back();
}

int main(int argc, char *argv[]) {
  int num = 1234509;
  auto ranks = IntegerOperations::getRanks(num);
  std::cout << "Сумма первого и последнего числа у " << num << " : "
            << getSumRanks(ranks) << '\n';
  return 0;
}
