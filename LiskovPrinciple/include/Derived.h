#pragma once

#include <Base.h>
#include <stdexcept>

class Derived : public Base {
private:
  int j = 5;

public:
  Derived() : Base() {}

  /// @throws exception
  Derived(int i, int j) : Base(i) {
    if (i < -5) { // ослабление пред-условий базового класса
      throw std::runtime_error("i is less than -5");
    }
    if (j < 5) {
      throw std::runtime_error("j is less than 5");
    }
  }
};
