#include <iostream>

int getLeastRank(int line) {
  int remainder = line % 10;
  line /= 10;
  return remainder;
}

int main(int argc, char *argv[]) {
  int i = 784;
  std::cout << getLeastRank(i) << '\n';
  return 0;
}
