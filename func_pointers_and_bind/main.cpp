#include <functional>
#include <iostream>

class A {
  int i;

public:
  A() = default; // конструктор по умолчанию
  A(int i) : i(i) {}
  ~A() = default; // деструктор

  int getI() const { return i; } // возвращает i
};

int add(int i, int j) { return i + j; }

int addA(const A &one, const A &two) { return add(one.getI(), two.getI()); }
int subA(const A &one, const A &two) { return one.getI() - two.getI(); }

inline int proc(const A &one, const A &two, int (*func)(const A &, const A &)) {
  return func(one, two);
}

int proc() { return 0; }

int main(int argc, char *argv[]) {
  A a(5);
  A aa(4);
  std::cout << proc(a, aa, addA) << '\n';
  // std::cout << proc(a, aa, subA) << '\n'; // boilerplate - шаблон!!! так
  // писать нельзя!!!
  auto bind_proc_a_aa = std::bind_front(
      static_cast<int (*)(const A &, const A &, int (*)(const A &, const A &))>(
          proc),
      a, aa);
  std::cout << bind_proc_a_aa(addA) << '\n';
  std::cout << bind_proc_a_aa(subA) << '\n';
  std::cout << proc() << '\n';
  return 0;
}
