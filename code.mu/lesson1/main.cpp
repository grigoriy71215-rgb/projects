#include <iostream>

void getNegativeAsIs(const int &number) {
  if (number < 0) {
    std::cout << number << '\n';
  } else {
    std::cout << "число положительное" << '\n';
  }
}

void getNegativeToBe(const int &number) {
  std::cout << "Число " << number
            << (number < 0 ? " отрицательное" : " положительное") << '\n';
}

int main(int argc, char *argv[]) {
  int number = 1234;
  getNegativeAsIs(number);
  getNegativeToBe(number);
  return 0;
}
