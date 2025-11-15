#include <iostream>
/* Задание на полиморфизм:
 * написать класс сложения двух чисел*/

/* Пример полиморфизма */
void f(int i) { std::cout << "F for int: " << i << '\n'; }

void f(float g) { std::cout << "F for float: " << g << '\n'; }

/* Решение задачи */

class A {};

int main() {
  int i = 42;
  float j = 50.8457;
  f(i);
  f(j);
  return 0;
}
