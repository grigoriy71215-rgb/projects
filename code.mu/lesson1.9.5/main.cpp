#include <iostream>
#include <operations/CharOperations.h>

int main(int argc, char *argv[]) {
  char chr1 = '1';
  char chr2 = '2';
  char chr3 = '3';
  char chr4 = '4';
  char chr5 = '5';
  int res = CharOperations::constructNumber({chr1, chr2, chr3, chr4, chr5});
  std::cout << "Число из символов " << chr1 << ", " << chr2 << ", " << chr3
            << ", " << chr4 << ", " << chr5 << " выглядит так: " << res << '\n';
  return 0;
}
