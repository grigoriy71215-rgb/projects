#include <iostream>
#include <string>

void printReverse(const std::string &str) {
  for (auto it = str.rbegin(); it != str.rend(); ++it)
    std::cout << *it;
  std::cout << '\n';
}

int main() {
  std::string str = "123456789";
  std::cout << "Строка " << str
            << ", выведенная с последнего символа к первому, выглядит так: ";
  printReverse(str);
  return 0;
}
