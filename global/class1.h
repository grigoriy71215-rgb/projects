#pragma once

#include <iostream>

#include <iostream>

int ourVariable = 5;

class Class1 {
public:
  Class1() { std::cout << ourVariable << '\n'; }
  ~Class1() = default;
};
