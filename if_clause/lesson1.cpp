#include <iostream>
/* Задача: вывести "Число i больше числа j", если это так, и ничего в противном
 * случае */
int main(int argc, char *argv[]) {
  int i = 5;
  int j = 4;
  if (i > j) {
    std::cout << "Число i больше числа j" << std::endl;
  }
  return 0;
}
