#include <iostream>

bool isOdd(int num) { return num % 2 == 1; }

int getSquare(int num) { return num * num; }

int getSum(int sum, int num) { return sum + getSquare(num); }

int main(int argc, char *argv[]) {
  int sum = 0;
  for (int i = 1; i <= 100; ++i) {
    if (isOdd(i)) {
      sum = getSum(sum, i);
    }
  }
  std::cout << "Сумма квадратов нечетных чисел от 1 до 100 равна " << sum
            << '\n';
  return 0;
}
