#include <iostream>
int main(int argc, char *argv[]) {
  int arr[] = {1, 2, 3, 4, 5, 6};
  size_t arr_size = sizeof(arr);
  std::cout << "Массив" << " содержит " << arr_size << " байт\n";
  return 0;
}
