#pragma once

#include <string>

class StringOperations {
private:
  int getInclusion(int value, int pos);
  int iterate(StringOperations *obj,
              int (StringOperations::*stepFunc)(int, int), int value, int pos);
  std::string ourString;
  std::string subString;

public:
  StringOperations();
  StringOperations(const std::string &ourString, const std::string &subString);
  ~StringOperations();

  int getCountOfOccurrences();
};
