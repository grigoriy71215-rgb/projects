#include "StringOperations.h"

int StringOperations::getSumRanksOfString(std::string &str) {
  int numberFromString = 0;
  for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
    if (*it >= 48 && *it <= 57)
      numberFromString += *it - 48;
  }
  return numberFromString;
}
