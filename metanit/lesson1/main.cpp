#include "Integral.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  Integral<int> i(5);
  std::cout << i.getValue() << '\n';
  i.setValue(4);
  std::cout << i.getValue() << '\n';
  return 0;
}
