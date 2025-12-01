#pragma once

int ourVariable = 0;

class Class2 {
public:
  Class2() { ourVariable += 2; }
  ~Class2() = default;
};
