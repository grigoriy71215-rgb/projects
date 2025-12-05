#include <cmath>
#include <cstdio>
#include <iostream>

void printUnsigned(const char *type, const double &value) {
  printf("Max value of %s is %0.f\n", type, value);
}

void printSigned(const char *type, const double &value) {
  printf("Min value of %s is -%0.f, max value of %s is %0.f\n", type, value / 2,
         type, value / 2);
}

int main(int argc, char *argv[]) {
  std::cout << sizeof(int) << '\n';
  std::cout << sizeof(short) << '\n';
  int intBits = 8 * sizeof(int);
  int shortBits = 8 * sizeof(short);
  double intMaxValue = std::pow(2, intBits - 1);
  double shortMaxValue = std::pow(2, shortBits - 1);
  printUnsigned("unsigned int", intMaxValue);
  printUnsigned("unsigned short", shortMaxValue);
  printSigned("int", intMaxValue);
  printSigned("short", shortMaxValue);
  return 0;
}
