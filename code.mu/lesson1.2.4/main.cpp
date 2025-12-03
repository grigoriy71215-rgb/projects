#include <iostream>

int getLeastRank(int &num) {
  int remainder = num % 10;
  num /= 10;
  return remainder;
}

int getLeastRankByValue(int num) { return getLeastRank(num); }

int deleteMinus(int number) {
  if (number >= 0)
    return number;
  else
    return 0 - number;
}

// в случае, если используются функции getLeastRank и getMainRank вместе,
// функция getLeastRank должна быть первой в вызове

int getMainRank(int &line) {
  int res = 0;
  while (line != 0) {
    res = getLeastRank(line);
  }
  return deleteMinus(res);
}

int main(int argc, char *argv[]) {
  int i = 1023098;
  std::cout << getLeastRank(i) + getMainRank(i) << '\n';
  return 0;
}
