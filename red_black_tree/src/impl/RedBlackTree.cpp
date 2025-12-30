#include "impl/RedBlackTree.h"
#include <memory>

RedBlackTree::RedBlackTree(std::shared_ptr<RedBlackTree> left,
                           std::shared_ptr<RedBlackTree> right,
                           std::shared_ptr<RedBlackTree> parent, Color color)
    : BinaryTree(left, right), parent(parent), color(color) {}

bool RedBlackTree::operator==(const BinaryTree &other) const noexcept {
  return parent == dynamic_cast<const RedBlackTree &>(other).parent &&
         left.get() == right.lock().get();
}

RedBlackTree &RedBlackTree::operator=(const RedBlackTree &other) {
  value = other.value;
  right = other.right;
  left = other.left;
  parent = other.parent;
  return *this;
}

RedBlackTree *RedBlackTree::insertByValue(std::shared_ptr<RedBlackTree> parent,
                                          int value) {
  if (this->value == 0) {
    this->value = value;
    if (parent == nullptr)
      color = Color::RED;
    else {
      color = Color::BLACK;
      this->parent = parent;
    }
    return this;
  } else if (this->value < value) {
    BinaryTree &right_ref = *right.lock().get();
    auto right_rb = dynamic_cast<RedBlackTree &>(right_ref);
    return right_rb.insertByValue(parent, value);
  } else {
    BinaryTree &left_ref = *left.get();
    return dynamic_cast<RedBlackTree &>(left_ref).insertByValue(parent, value);
  }
}

void RedBlackTree::insertValue(int value) {
  RedBlackTree *newNode = insertByValue(parent, value);
  if (parent)
}

std::shared_ptr<BinaryTree> RedBlackTree::getLeft() { return left; }

std::shared_ptr<BinaryTree> RedBlackTree::getRight() { return right.lock(); }
