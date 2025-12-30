#pragma once

#include <initializer_list>
class CharOperations {
private:
  CharOperations() = delete;

public:
  static int constructNumber(std::initializer_list<char> charInitializerList);
};
