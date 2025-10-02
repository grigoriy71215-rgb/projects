#include "addition.h"

unsigned char Addition::add(const unsigned char &firstTerm, // вводим два числа
                            const unsigned char &secondTerm) {
  return firstTerm + secondTerm; // складываем эти два числа
}

int Addition::add(const int &firstTerm,
                  const int &secondTerm) { // вводим два числа
  return firstTerm + secondTerm;           // складываем эти два числа
}

float Addition::add(const float &firstTerm,
                    const float &secondTerm) { // вводим два числа
  return firstTerm + secondTerm;               // складываем эти два числа
}

long Addition::add(const long &firstTerm,
                   const long &secondTerm) { // вводим два числа
  return firstTerm + secondTerm;             // складываем эти два числа
}

double Addition::add(const double &firstTerm,
                     const double &secondTerm) { // вводим два числа
  return firstTerm + secondTerm;                 // складываем эти два числа
}
