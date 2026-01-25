#include <algorithm>
#include <iostream>
#include <numeric>

int getSquare(int num) { return num * num; }

int main(int argc, char *argv[]) {
  int arr[] = {1, 2, 3, 4, 5};
  int sum = 0;
  size_t size = sizeof(arr) / sizeof(int);
  std::cout << "Сумма квадратов элементов массива \n";
  std::for_each(arr, arr + size, [&](int &i) { std::cout << i << ' '; });
  std::cout << "\nравна ";
  sum = std::accumulate(arr, arr + size, 0,
                        [](int acc, int &i) { return acc + i * i; });
  std::cout << sum << '\n';
  return 0;
}
