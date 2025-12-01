#include "A.h"
#include "B.h"
#include <iostream>

int f();

int main() {
  std::cout << f() << '\n';
  B b;
  b.bb = 5;
  A a(b);
  std::cout << a.returnBB() << '\n';
}

int f() { return 5; }
