#include "Float.h"
#include <iostream>

int main(int argc, char *argv[]) {
  Float f(5, -5);
  std::cout << std::format("{:f}\n", f.getFloat()) << '\n';
  return 0;
}
