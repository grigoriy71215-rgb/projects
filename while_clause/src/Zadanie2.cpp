#include "Zadanie2.h"

Zadanie2::Zadanie2(int a, int b) : a(a), b(b) {}

int Zadanie2::getRemainder(int &&a, int &&b) {
  a = a % b;
  return a;
}

int Zadanie2::getNOD() {
  while (a != 0 && b != 0)
    if (a > b) {
      a %= b;
    } else {
      b %= a;
    }
  return a + b;
}
