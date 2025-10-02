#include <iostream>

class A {
  public:
    void f() {
      std::cout << "hello from A\n";
    }
};

void f() {
  std::cout << "hello from global" << '\n';
}

void g(void (*method)()) {
  method();
}

void g(A *a, void (A::*method)()) {
  (a->*method)();
}

int main(int argc, char *argv[]) {
  g(f);
  A *a = new A();
  g(a, &A::f);
  return 0;
}
