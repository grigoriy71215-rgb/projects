#include <iostream>
class A {
protected:
  int i;
  A() = default;

public:
  A(int i) : i(i) {}
  virtual ~A() = default;

  int getI() const { return i; }
};

class B : public A {
  int j;

public:
  B() : A() {}
  B(int i, int j) : A(i), j(j) {}

  int getJ() const { return j; }
};

int main() {
  A *a = new B(5, 4);
  std::cout << a->getI() << '\n';
  // std::cout << a->getJ() << '\n'; -- not worked
  std::cout << dynamic_cast<B *>(a)->getJ() << '\n';
  delete a;
}
