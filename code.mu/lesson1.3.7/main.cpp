#include <iostream>

bool checkIsEven(const int &num) { return num % 2 == 0; }

void printEven(const int &num) {
  if (checkIsEven(num))
    std::cout << num << '\n';
}

void printOdd(const int &num) {
  if (!checkIsEven(num))
    std::cout << num << '\n';
}

void printEvenBetweenTwoAndTousand() {
  for (int i = 2; i <= 1000; ++i)
    printEven(i);
}

void printBetweenOneAndThousandForLambda(void (*func)(const int &)) {
  for (int i = 990; i <= 1000; ++i)
    func(i);
}

int main(int argc, char *argv[]) {
  printBetweenOneAndThousandForLambda(printOdd);
  return 0;
}
