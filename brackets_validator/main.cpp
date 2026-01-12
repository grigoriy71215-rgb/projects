#include <iostream>
#include <string>

bool checkBrackets(const std::string &str) {
  auto it = str.begin();
  if (*it == ')')
    return false;
  if (*--str.end() == '(')
    return false;
  int openBracketCounter = 0;
  int closeBracketCounter = 0;
  for (; it < str.end(); ++it) {
    if (*it == '(')
      ++openBracketCounter;
    else if (*it == ')')
      ++closeBracketCounter;
  }
  return openBracketCounter == closeBracketCounter;
}

int main(int argc, char *argv[]) {
  std::string str = "((())";
  std::cout << "Количество скобок открывающихся "
            << (!checkBrackets(str) ? "не " : "")
            << "совпадает с количеством закрывающихся " << '\n';
  return 0;
}
