#include <cstddef>
#include <iostream>
int getSumElements(int *arr, size_t size) {
  int sum = 0;
  for (int i = 0; i < size; ++i) {
    sum += arr[i];
  }
  return sum;
}

int main(int argc, char *argv[]) {
  int arr[] = {1, 2, 3, 4, 5};
  size_t size = sizeof(arr) / sizeof(int);
  std::cout << "Сумма элементов массива " << arr << " : "
            << getSumElements(arr, size) << '\n';
  return 0;
}
