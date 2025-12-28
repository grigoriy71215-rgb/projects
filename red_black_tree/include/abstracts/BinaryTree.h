#pragma once

#include <memory>

class BinaryTree {
protected:
  std::shared_ptr<BinaryTree> left = nullptr;
  std::weak_ptr<BinaryTree> right;
  int value = 0;
  bool valid = false;

  BinaryTree() = default;
  BinaryTree(std::shared_ptr<BinaryTree> left,
             std::shared_ptr<BinaryTree> right);

  virtual void checkValidness();

public:
  bool isValid() const { return valid; }
  virtual ~BinaryTree() = default;
  bool operator==(BinaryTree &other) const noexcept;

  virtual void insertValue(int value) = 0;
  virtual void updateValue(int value) = 0;
  virtual std::shared_ptr<BinaryTree> findValue(int value) = 0;
  virtual void deleteValue(int value) = 0;

  BinaryTree(const BinaryTree &other) noexcept;
};
