#include <stdexcept>
#include <iostream>

class A {
  public:
    void f() {
      std::cout << 'a' << '\n';
      int i = 1 / 0;
    }
};

int main() {
  A a;
  try {
    a.f();
  } catch (std::exception ex) {
    std::cout << ex.what() << '\n';
  }
  return 0;
}
