#include "./include/MyClass.h" // библиотека данных для потока вывода MyClass
#include <iostream>            // библиотека данных для потока вывода cout

void print(MyClass *myClass) { //
  std::cout << myClass->getI() << '\n';
}

int main() { // записывае функци
  MyClass *myClass = new MyClass(42);
  print(myClass);
  myClass->setI(10);
  print(myClass);
  delete myClass;
  return 0;
}
