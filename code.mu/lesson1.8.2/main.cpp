#include <iostream>
#include <string>

void printBackwards(const std::string &str) {
  for (auto it = --str.end(); it >= str.begin(); --it) {
    std::cout << *it;
  }
  std::cout << '\n';
}

int main(int argc, char *argv[]) {
  std::string str = "abcde";
  std::cout << "Строка '" << str << "', выведенная наоборот: ";
  printBackwards(str);
  return 0;
}
