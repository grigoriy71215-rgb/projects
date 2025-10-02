#include <iostream>

void f(const int &i) { std::cout << "Copy i: " << i << '\n'; }

void f(int &&i) {
  std::cout << "Move i: " << i << '\n';
  i = 5;
}

int main(int argc, char *argv[]) {
  int i = 7;
  f(i);
  f(std::move(i));
  std::cout << i << '\n';
  auto copy_cout = [i]() { std::cout << i << '\n'; };
  auto move_cout = [&i]() {
    std::cout << i << '\n';
    i = 8;
  };
  copy_cout();
  move_cout();
  std::cout << i << '\n';
  return 0;
}
