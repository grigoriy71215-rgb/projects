#include "CharOperations.h"
#include <algorithm>

int CharOperations::constructNumber(
    std::initializer_list<char> charInitializerList) {
  int res = 0;
  std::for_each(charInitializerList.begin(), charInitializerList.end(),
                [&](char ch) {
                  int charValue = (ch >= 48 && ch <= 57) ? (ch - 48) : -1;
                  if (charValue != -1) {
                    res *= 10;
                    res += charValue;
                  }
                });
  return res;
}
