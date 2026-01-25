#pragma once

#include <vector>

class IntegerOperations {
private:
  IntegerOperations() = delete;
  static void moveLeastRankFromSourceToDest(int &source, int &dest);
  static int getNextRank(int &number);

public:
  static int getLeastRank(int &num);
  static int reverse(int num);
  static std::vector<int> getRanks(int number);
};
