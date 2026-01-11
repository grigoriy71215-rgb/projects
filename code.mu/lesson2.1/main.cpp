#include <iostream>

int main(int argc, char *argv[]) {
  int arr[] = {1, 2, 3, 4, 5};
  size_t arr_size = sizeof(arr) / sizeof(int);
  std::cout << "Количество элементов у массива { ";
  for (int i = 0; i < arr_size; ++i)
    std::cout << arr[i] << ' ';
  std::cout << "} равно " << arr_size << '\n';
  return 0;
}
