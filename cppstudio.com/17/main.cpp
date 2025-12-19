#include <iostream>
#include <stdexcept>
#include <string>

bool checkForDigit(char ch) { return ch >= 48 && ch <= 57; }

// returns 0 if digit is not found
char findDigitInStringByPosition(const std::string &str,
                                 const size_t digitPosition) {
  if (str.size() < digitPosition)
    throw std::invalid_argument("String length is less than pos");
  auto it = str.begin();
  size_t countOfPassedDigits = 0;
  while (it < str.end()) {
    if (checkForDigit(*it)) {
      if ((countOfPassedDigits + 1) == digitPosition)
        return *it;
      else
        ++countOfPassedDigits;
    }
    ++it;
  }
  return 0;
}

int main(int argc, char *argv[]) {
  std::cout << "Введите строку: ";
  std::string str;
  std::cin >> str;
  std::cout << "Введите позицию искомой цифры: ";
  size_t pos;
  std::cin >> pos;
  std::cout << findDigitInStringByPosition(str, pos) << '\n';
  return 0;
}
