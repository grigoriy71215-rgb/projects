#include "Set.h"
#include <iostream>

int main(int argc, char *argv[]) {
  Set s(5);
  s.insert(6);
  std::cout << s.getVal() << '\n';
  std::cout << s.getRight() << '\n';
  std::cout << s.getLeft() << '\n';
  return 0;
}
