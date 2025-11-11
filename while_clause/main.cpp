#include "Zadanie1.h"
#include <expected>
#include <iostream>
#include <memory>

int main(int argc, char *argv[]) {
  int digit = 345098;
  auto zadanie1 = std::unique_ptr<Zadanie1>();
  std::cout << zadanie1->getCountOfRanks(std::move(digit)) << '\n';
  return 0;
}
