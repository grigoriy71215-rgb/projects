#include "Set.h"
#include <limits>

Set::Set(int val) { insert(val); }

void Set::insert(int val) {
  if (this->val == 0)
    this->val = val;
  else if (val < this->val)
    left = std::make_unique<Set>(val);
  else
    right = std::make_unique<Set>(val);
}

void Set::implace(int val) {
  if (left == nullptr && right == nullptr)
    this->val = val;
  else
    insert(val);
}

int Set::getRight() const {
  return right == nullptr ? std::numeric_limits<int>::min() : right->getVal();
}

int Set::getLeft() const {
  return left == nullptr ? std::numeric_limits<int>::min() : left->getVal();
}
