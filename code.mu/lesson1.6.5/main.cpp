#include <iostream>
float getPercents(float num1, float num2) { return num1 / num2 * 100; }

int main(int argc, char *argv[]) {
  float num1 = 37;
  float num2 = 12;
  std::cout << "Количество процентов в " << num1 << " от " << num2 << " равно "
            << getPercents(num1, num2) << '\n';
  return 0;
}
