#include <bitset>
#include <iostream>

using bin = std::bitset<sizeof(int) * 8>;

int main(int argc, char *argv[]) {
  int i = -3;
  unsigned int ii = -3;
  // ii = -3; // ub - undefined behavior - неопределенное поведение
  std::cout << bin(ii) << '\n';
  return 0;
}
