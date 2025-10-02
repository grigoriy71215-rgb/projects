// Задача: подсчитать количество нечетных элементов массива
// Дано: массив содержит следующие элементы: 3, 4, 5, 10, 12
// Рекомендации: использовать std::vector<int> для хранения элементов массива

#include <iostream>
#include <vector>

std::vector<int> numbers = {3, 4, 5, 10, 12};

int main(int argc, char *argv[]) {
  int kolichestvo = 0;
  for (auto it = numbers.begin(); it != numbers.end(); ++it) {
    int znatchenie = *it;
    int tchastnoe = znatchenie / 2;
    bool ostatok = znatchenie - 2 * tchastnoe;
    if (ostatok == 1)
      ++kolichestvo;
  }
  std::cout << kolichestvo << '\n';
  return 0;
}
