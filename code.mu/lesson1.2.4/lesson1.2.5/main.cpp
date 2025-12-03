#include <iostream>

void deleteByTen(int &num) { num /= 10; }

int getCountOfRanks(int &line) {
  int res = 0;
  while (line != 0) {
    deleteByTen(line);
    std::cout << line << ' ';
    ++res;
  }
  std::cout << '\n';
  return res;
}

int main(int argc, char *argv[]) {
  int i = 1023098;
  std::cout << getCountOfRanks(i) << '\n';
  return 0;
}
