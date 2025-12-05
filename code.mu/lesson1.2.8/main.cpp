#include <iostream>
void deleteRank(int &number) { number /= 10; }

int getCountOfRanks(int &number) {
  int res = 0;
  while (number != 0) {
    deleteRank(number);
    ++res;
  }
  return res;
}

int main(int argc, char *argv[]) {
  int i = 3;
  std::cout << "Число " << i << " является двузначным? - "
            << (getCountOfRanks(i) == 2 ? "да!" : "нет!") << '\n';
  return 0;
}
