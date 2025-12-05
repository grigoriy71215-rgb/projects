#include <iostream>
#include <string>

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
  int number = 89273478;
  std::string str = " числа " + std::to_string(number);
  int leastRank = getLeastRank(number);
  int mainRank = getMainRank(number);
  if (leastRank == mainRank)
    std::cout << "Младший разряд " << leastRank << " и старший разряд "
              << mainRank << str << " совпадают\n";
  else
    std::cout << "Младший разряд " << leastRank << " и старший разряд "
              << mainRank << str << " не совпадают\n";
  return 0;
}
