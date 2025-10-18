#include <iostream>

int sum5(int i, int j, int k) { return 5 * (i + j + k); }

int mul(int i, int j, int k) { return i * j * k; }

int main(int argc, char *argv[]) {
  for (int i = 1; i < 10; ++i)
    for (int j = 2; j < 10; ++j)
      for (int k = 3; k < 10; ++k) {
        if (mul(i, j, k) == sum5(i, j, k))
          std::cout << "i=" << i << "; j=" << j << "; k=" << k << '\n';
      }
  return 0;
}
