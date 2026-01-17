#include <cstddef>
#include <iostream>
#include <string>
char getFirstCharOfString(const std::string &str) { return *str.begin(); }

int main(int argc, char *argv[]) {
  std::string arr[] = {"123", "456", "789"};
  size_t arr_length = sizeof(arr) / sizeof(std::string);
  for (size_t i = 0; i < arr_length; ++i) {
    std::cout << "Первые символы каждого элемента строки выглядят так "
              << getFirstCharOfString(arr[i]) << '\n';
  }
  return 0;
}
