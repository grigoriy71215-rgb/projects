#include <iostream>
#include <string>

void addToString(std::string &str, std::initializer_list<char> chil) {
  for (auto ch : chil)
    str += ch;
}

void printCharsInIL(std::initializer_list<char> chil) {
  for (auto ch : chil) {
    std::cout << ch << ' ';
  }
}

int main() {
  char chr1 = 'a';
  char chr2 = 'b';
  char chr3 = 'c';
  char chr4 = 'z';
  char chr5 = 'f';
  std::string str;
  addToString(str, {chr1, chr2, chr3, chr4, chr5});

  std::cout << "Символы ";
  printCharsInIL({chr1, chr2, chr3, chr4, chr5});
  std::cout << " в строку: " << str << '\n';

  return 0;
}
