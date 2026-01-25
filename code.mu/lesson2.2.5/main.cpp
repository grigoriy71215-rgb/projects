#include <algorithm>
#include <iostream>
#include <operations/IntegerOperations.h>

int main(int argc, char *argv[]) {
  int num = 12345;
  auto ranks = IntegerOperations::getRanks(num);
  std::cout << "Вывод разрядов числа " << num << " наоборот: ";
  std::for_each(ranks.rbegin(), ranks.rend(),
                [](int &i) { std::cout << i << ' '; });
  std::cout << '\n';
  return 0;
}
