#include <functional>
#include <iostream>

int add(int i, int j) { return i + j; }

auto getAdd3() { return std::bind(add, 3, std::placeholders::_1); }

int main(int argc, char *argv[]) {
  auto add3 = getAdd3();
  std::cout << add3(4) << '\n';
  return 0;
}
