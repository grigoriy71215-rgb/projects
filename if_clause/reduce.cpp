#include <iostream>
#include <vector>

std::vector<int> vint = {1, 2, 3, 4, 5};

int enumerateAndProcess(int (*funct)(int, int), int summary) {
  for (auto it = vint.begin(); it < vint.end(); ++it) {
    summary = funct(*it, summary);
  }
  return summary;
}

int reduce(int element, int summary) { return summary + element; }

int reduceOdd(int element, int summary) {
  return summary + (element % 2 == 1 ? element : 0);
}

void reductVint() {
  std::cout << enumerateAndProcess(reduce, 0) << '\n';
  std::cout << enumerateAndProcess(reduceOdd, 0) << '\n';
}

int main(int argc, char *argv[]) {
  reductVint();
  return 0;
}
