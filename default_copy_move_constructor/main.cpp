#include <iostream>
class A {
private:
  int i = 5;

public:
  A() {
    i = 6;
    std::cout << "default ctor\n";
  }
  // A(const A &a) = default;
  int getI() const noexcept { return i; }
  void setI(int i) { this->i = i; }
};

int main(int argc, char *argv[]) {
  A a;
  std::cout << a.getI() << '\n';
  a.setI(7);
  A aa = a;
  std::cout << aa.getI() << '\n';
  return 0;
}
