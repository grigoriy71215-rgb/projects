#include "ConsumerCredit.cpp"
#include "Credit.hpp"
#include "Factoring.cpp"
#include <iostream>
#include <string>

Credit *selectCredit(const std::string &clientName, int sum) {
  if (sum < 10000)
    return new Factoring(clientName, sum);
  else
    return new ConsumerCredit(clientName, sum);
}

int main(int argc, char *argv[]) {
  std::string clientName = "Grigory";
  constexpr int sum = 1000000;
  Credit *credit = selectCredit(clientName, sum);
  std::cout << credit->getCreditName() << '\n';
  delete credit;
  return 0;
}
