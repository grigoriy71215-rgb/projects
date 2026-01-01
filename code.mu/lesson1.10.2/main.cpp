#include <array>
#include <iostream>
#include <string>

int getHours(int year) { return year * 365 * 24; }

std::array<int, 2> getTwoLeastRanks(int year) {
  std::array<int, 2> res;
  int i = 0;
  while (i < 2 && year != 0) {
    res[i] = year % 10;
    year /= 10;
    ++i;
  }
  return res;
}

bool getYearExpression(int year) {
  std::array<int, 2> twoLeastRanks = getTwoLeastRanks(year);
  if (twoLeastRanks[0] == 1 && (twoLeastRanks[1] != 1))
    return true;
  else
    return false;
}

std::string getYearWordEnding(int year) {
  return (getYearExpression(year) ? "у" : "ax");
}

int main(int argc, char *argv[]) {
  int year = 111;
  std::cout << "Количество часов в " << year << " год"
            << getYearWordEnding(year) << " равно " << getHours(year) << '\n';
  return 0;
}
