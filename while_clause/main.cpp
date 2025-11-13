#include "Zadanie2.h"
#include <iostream>
#include <memory>

int main(int argc, char *argv[]) {
  int a = 34;
  int b = 17;
  auto zadanie2 = std::make_unique<Zadanie2>(a, b);
  std::cout << zadanie2->getNOD() << '\n';
  return 0;
}
