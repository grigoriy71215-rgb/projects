#include <operations/IntegerOperations.h>
#include <utilities/system/CoutExtended.h>

void sumRank(int &sum, int &num) {
  sum += IntegerOperations::getLeastRank(num);
}

int sumOfDigits(int num) {
  int sum = 0;
  while (num != 0)
    sumRank(sum, num);
  return sum;
}

int main(int argc, char *argv[]) {
  int num = 1232183;
  CoutExtended cout;
  cout.setPrecision(0);
  cout << "Сумма цифр числа " << (double)num << " равна "
       << (double)sumOfDigits(num) << '\n';
  return 0;
}
