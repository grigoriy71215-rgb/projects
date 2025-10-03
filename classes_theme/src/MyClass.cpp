#include "../include/MyClass.h"

MyClass::MyClass() { this->i = 0; }

MyClass::MyClass(int i) { this->i = i; }

MyClass::~MyClass() {}

int MyClass::getI() const noexcept { return i; }

void MyClass::setI(int i) { this->i = i; }
