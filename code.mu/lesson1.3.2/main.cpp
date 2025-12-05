#include <iostream>
void printNumbers() {
  for (int i = 1; i <= 100; ++i) {
    std::cout << i << '\n';
  }
}

int main(int argc, char *argv[]) {
  printNumbers();
  return 0;
}
