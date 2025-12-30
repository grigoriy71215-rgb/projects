#include "abstracts/BinaryTree.h"

BinaryTree::BinaryTree(std::shared_ptr<BinaryTree> left,
                       std::shared_ptr<BinaryTree> right)
    : left(left), right(right) {
  checkValidness();
}

void BinaryTree::checkValidness() {
  valid = (left.get() != right.lock().get());
}

bool BinaryTree::operator==(const BinaryTree &other) const noexcept {
  return value == other.value && left.get() == right.lock().get();
}

BinaryTree::BinaryTree(const BinaryTree &other) noexcept {
  left = other.left;
  right = other.right.lock();
}
