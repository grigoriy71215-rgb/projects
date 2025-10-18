#include <iostream>
#include <string>

#include "./abstracts/Credit.hpp"
#include "./impl/ConsumerCredit.hpp"

int main(int argc, char *argv[]) {
  int creditSum = 100;
  std::string clientName = "Grisha";
  Credit *credit = new ConsumerCredit(clientName, creditSum);
  std::cout << credit->getCreditIssue() << '\n';
  delete credit;
  return 0;
}
