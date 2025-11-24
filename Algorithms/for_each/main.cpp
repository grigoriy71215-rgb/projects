#include <algorithm>
#include <execution>
#include <iostream>
#include <vector>

std::vector<int> numbers = {1, 2, 3, 4, 5};
// Увеличить каждый элемент на 10
void increaseByTen() {
  std::for_each(std::execution::par, numbers.begin(), numbers.end(),
                [](int &number) { number += 10; });
}

void print() {
  std::for_each(std::execution::par, numbers.begin(), numbers.end(),
                [](const int &number) { std::cout << number << " "; });
}

// Умножить каждый элемент на 2

void multiplyByTwo() {
  std::for_each(std::execution::par, numbers.begin(), numbers.end(),
                [](int &number) { number *= 2; });
}

int main(int argc, char *argv[]) {
  increaseByTen();
  multiplyByTwo();
  print();
  std::cout << '\n';
  return 0;
}
