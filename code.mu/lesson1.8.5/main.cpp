#include <iostream>

float getTenPercents(float num) { return num / 10; }

int main(int argc, char *argv[]) {
  float num = 12.3;
  std::cout << "10 процентов от " << num << " равно " << getTenPercents(num)
            << '\n';
  return 0;
}
