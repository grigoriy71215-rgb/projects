#pragma once

class MyClass {
private:
  int i = 0;

public:
  MyClass();
  MyClass(int i);
  ~MyClass();

  int getI() const noexcept;
  void setI(int i);
};
