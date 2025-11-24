#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> numbers = {5, 2, 8, 1, 9};
int pivot = 5;
// Отсортировать: сначала числа меньше pivot, затем больше или равные

void sortByPivot() {
  std::sort(numbers.begin(), numbers.end(), [](const int &one, const int &two) {
    // Сначала числа меньше pivot, затем больше или равные
    bool one_less = (one < pivot);
    bool two_less = (two < pivot);
    if (one_less && !two_less)
      return true; // one идет перед two
    if (!one_less && two_less)
      return false;   // two идет перед one
    return one < two; // внутри групп сортируем по возрас
  });
}

void print() {
  std::for_each(numbers.cbegin(), numbers.cend(),
                [](const int &one) { std::cout << one << '\n'; });
}

int main(int argc, char *argv[]) {
  sortByPivot();
  print();
  return 0;
}
