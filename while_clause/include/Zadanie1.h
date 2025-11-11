#pragma once

class Zadanie1 final {
private:
  void cutLeastRank(int &&digit);

public:
  Zadanie1() = default;
  ~Zadanie1() = default;
  int getCountOfRanks(int &&digit);
};
