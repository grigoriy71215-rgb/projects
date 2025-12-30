#pragma once

#include "abstracts/BinaryTree.h"

class RedBlackTree : public BinaryTree {
public:
  enum Color { RED, BLACK };

protected:
  std::shared_ptr<RedBlackTree> parent = nullptr;
  Color color;
  RedBlackTree() = default;

public:
  RedBlackTree(std::shared_ptr<RedBlackTree> left,
               std::shared_ptr<RedBlackTree> right,
               std::shared_ptr<RedBlackTree> parent, Color color);
  virtual ~RedBlackTree() = default;

  RedBlackTree &operator=(const RedBlackTree &other);

  virtual bool operator==(const BinaryTree &other) const noexcept override;
  bool operator<=>(const BinaryTree &other) const noexcept;

  std::shared_ptr<BinaryTree> getLeft();
  std::shared_ptr<BinaryTree> getRight();

  virtual void insertValue(int value) override;
  virtual void updateValue(int value) override;
  virtual std::shared_ptr<BinaryTree> findValue(int value) override;
  virtual void deleteValue(int value) override;

private:
  RedBlackTree *insertByValue(std::shared_ptr<RedBlackTree> parent, int value);
};
