

#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
int main(int argc, char *argv[]) {
  int arr[] = {1, 9, 2, 3, 4, 5};
  size_t length = sizeof(arr) / sizeof(int);
  int sum = std::accumulate(arr, arr + length, 0, std::plus<>());
  std::cout << "Среднее арифметическое массива \n";
  std::for_each(arr, arr + length, [](int &i) { std::cout << i << ' '; });
  std::cout << "\nравно " << sum / length;
  std::cout << '\n';
  return 0;
}
