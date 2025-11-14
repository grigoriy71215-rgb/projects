#pragma once

#include "Derived.h"
#include <stdexcept>

class Base {
protected:
  int i = 0;

public:
  Base() = default;
  Base(int i) {
    if (i <= 0)
      throw std::runtime_error("i is not positive");
    this->i = i;
    if (static_cast<Derived *>(this)->j <
        3) { // усиление пост-условий дочернего класса
      throw std::runtime_error("j is less than 3");
    }
  }

  int getI() const { return i; }
};
