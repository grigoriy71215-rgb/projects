#include <algorithm>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

const std::string hexCharacterDictionary = "01234356789abcfef";

void printStdVersionOfHex(int i) { std::cout << "0x" << std::hex << i << '\n'; }

char getLeastHex(int &num) {
  int remainder = num % 16;
  num /= 16;
  return *(hexCharacterDictionary.begin() + remainder);
}

std::vector<char> getHexCharacters(int num) {
  std::vector<char> hexCharacters;
  while (num != 0) {
    char ch = getLeastHex(num);
    hexCharacters.push_back(ch);
  }
  std::reverse(hexCharacters.begin(), hexCharacters.end());
  return hexCharacters;
}

void printHexManually(int i) {}

int main(int argc, char *argv[]) {
  int i = 46;
  std::cout << "0x";
  for (auto ch : getHexCharacters(i))
    std::cout << ch;
  std::cout << '\n';
  return 0;
}
