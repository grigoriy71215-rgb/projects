#include "addition.h"
#include <iostream>
/* Задание на полиморфизм:
 * написать класс сложения двух чисел*/

/* Пример полиморфизма */
void f(int i) { std::cout << "F for int" << '\n'; }

void f(float g) { std::cout << "F for float" << '\n'; }

/* Решение задачи */

class A {};

int main() {
  int i = 5;
  int j = 3;
  std::cout << Addition::add(i, j)
            << '\n'; // статический вызов метода int add(int, int)
  return 0;
}
