#include <functional>
#include <iostream>
#include <string>

void swap(int &num1, int &num2) {
  int bubble = num1;
  num1 = num2;
  num2 = bubble;
}

void check(int &num1, int &num2) {
  if (num1 < num2) {
    swap(num1, num2);
  }
}

int getRemainder(int num1, int num2) { return num1 % num2; }

void print(int num1, int num2) {
  std::cout << "Остаток от деления " << num1 << " на: " << num2 << " равен "
            << getRemainder(num1, num2) << '\n';
}

void print_hof(int num1, int num2, std::string_view prefix,
               std::string_view equal, int (*func)(int, int)) {
  std::cout << prefix << num1 << " на " << num2 << equal << func(num1, num2)
            << '\n';
}

int main(int argc, char *argv[]) {
  int num1 = 76;
  int num2 = 12;
  check(num1, num2);
  std::string prefix = "Остаток от деления ";
  std::string equal = " равен ";
  // auto print_hof_ptr =
  //     std::bind(print_hof, std::placeholders::_1, std::placeholders::_2,
  //     prefix,
  //               equal, getRemainder);
  // print_hof_ptr(num1, num2);
  auto print_hof_ptr = std::bind_back(print_hof, prefix, equal, getRemainder);
  print_hof_ptr(num1, num2);
  print_hof(num1, num2, prefix, equal, getRemainder);
  print(num1, num2);
  return 0;
}
