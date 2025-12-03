#include <iostream>

int getLeastRank(int &num) {
  int remainder = num % 10;
  num /= 10;
  return remainder;
}

int deleteMinus(int number) {
  if (number >= 0)
    return number;
  else
    return 0 - number;
}

int getMainRank(int line) {
  int res = 0;
  while (line != 0) {
    res = getLeastRank(line);
  }
  return deleteMinus(res);
}

int main(int argc, char *argv[]) {
  std::cout << getMainRank(-10) << '\n';
  return 0;
}
