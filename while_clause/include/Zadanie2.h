#pragma once

class Zadanie2 final {
private:
  int a = 0;
  int b = 0;
  int getRemainder(int &&a, int &&b);

public:
  Zadanie2() = default;
  Zadanie2(int a, int b);
  ~Zadanie2() = default;

  int getNOD();
};
