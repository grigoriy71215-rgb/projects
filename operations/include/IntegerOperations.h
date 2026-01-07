#pragma once

class IntegerOperations {
private:
  IntegerOperations() = delete;
  static void moveLeastRankFromSourceToDest(int &source, int &dest);

public:
  static int getLeastRank(int &num);
  static int reverse(int num);
};
