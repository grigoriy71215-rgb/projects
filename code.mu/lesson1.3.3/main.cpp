#include <iostream>
#include <string>

// возвращает 0, если длина строки < 2
char getPreLastChar(const std::string &str) {
  if (str.length() > 1) {
    return *(str.end() - 2);
  }
  return 0;
}

int main(int argc, char *argv[]) {
  char ch = getPreLastChar("st");
  if (ch == 0)
    std::cout << "String length is less than 2\n";
  else
    std::cout << ch << '\n';
  return 0;
}
