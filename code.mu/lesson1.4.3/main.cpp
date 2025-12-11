#include <iostream>
#include <string>

void printStringByChar(const std::string &str) {
  for (auto it = str.cbegin(); it < str.cend(); ++it) {
    std::cout << *it << '\n';
  }
}

int main(int argc, char *argv[]) {
  std::string str = "abcde";
  printStringByChar(str);
  return 0;
}
