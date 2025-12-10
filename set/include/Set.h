#pragma once

#include <memory>
class Set {
protected:
  int val = 0;
  std::unique_ptr<Set> left = nullptr;
  std::unique_ptr<Set> right = nullptr;
  Set() = default;

public:
  Set(int val);
  Set(const Set &other);
  Set(Set &&other) noexcept;

  Set &operator=(const Set &other);
  Set &operator=(Set &&other) noexcept;

  int getVal() const { return val; }
  int getRight() const;
  int getLeft() const;

  void implace(int val);
  void insert(int val);
};
