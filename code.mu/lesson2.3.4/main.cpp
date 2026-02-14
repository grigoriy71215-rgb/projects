#include <iostream>
int main(int argc, char *argv[]) {
  unsigned int arr[10];
  std::cout << " Массив " << arr << "  с целыми числами от 1 до 10 : ";
  for (int i = 0; i < 10; ++i) {
    arr[i] = i + 1;
    std::cout << arr[i] << ' ';
  }
  std::cout << '\n';
  return 0;
}
