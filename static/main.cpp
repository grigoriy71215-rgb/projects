#include <iostream>
class A {
public:
  static int i;
};

int A::i = 3;

int main() {
  A aa;
  aa.i = 5;
  A aaa;
  aaa.i = 6;
  std::cout << aa.i << '\n';
  return 0;
}
