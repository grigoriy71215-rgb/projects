#include <iostream>

int main(int argc, char *argv[]) {
  int i = 42;
  int j = 43;
  auto addition = [i, &j]() { return i + j; };
  i = 44;
  j = 3;
  std::cout << addition() << '\n';
  return 0;
}
