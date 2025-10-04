#include "./include/MyClass.h" // библиотека данных для потока вывода MyClass
#include <iostream>            // библиотека данных для потока вывода cout

void print(MyClass *myClass) {          // выводим myClass
  std::cout << myClass->getI() << '\n'; // выводим myClass->getI()
}

int main() { // записываем функцию с которой начинает программа
  MyClass *myClass = new MyClass(42); //
  print(myClass);                     //
  myClass->setI(10);                  // выводим на экран 10
  print(myClass);
  delete myClass;
  return 0;
}
