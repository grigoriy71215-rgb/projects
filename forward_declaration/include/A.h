#pragma once

#include <memory>

class B;

class A {
private:
  std::unique_ptr<B> b_ptr;

public:
  A(const B &b);
  ~A() = default;

  int returnBB() const;
};
