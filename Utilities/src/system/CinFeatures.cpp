#include "system/CinFeatures.h"
#include <iostream>
#include <limits>

void CinFeatures::clear() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
