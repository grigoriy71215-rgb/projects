/* Задача: Трое детей катаются на качелях. Даны веса всех детей (A, B, C) и
 * максимально допустимая разница в кг (D) для того, чтобы качаться было хорошо.
 * Расчитать, какую массу камней должны взять дети, масса которых меньше, чтобы
 * разница весов была равна D
 *
 * Входные данные: A, B, C, D должны вводиться с клавиатуры пользователем */

/* Размышления:
 * 1. Веса детей хранить в массиве std::vector<int>
 * 2. Максимально допустимую разницу D хранить в int
 * 3. Ответ будет выводиться в целых числах*/

#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <numeric>
#include <vector>

using vinti = std::vector<int>::iterator;

class SeeSaw final {
private: // скрытые члены класса
  std::vector<int> childrenWeights;
  int maxDifference = 0;

  auto getMiddleOfVector() {
    return childrenWeights.begin() + childrenWeights.size() / 2;
  }

  int getWeight(const vinti &begin, const vinti &end) {
    return std::reduce(begin, end, 0, [](int a, int b) { return a + b; });
  }

  void sortChildrenWeight() {
    std::sort(childrenWeights.begin(), childrenWeights.end(),
              std::greater<int>());
  }

  int getRightWeight() {
    return getWeight(getMiddleOfVector(), childrenWeights.end());
  }

  int getLeftWeight() {
    auto middleLeft = getMiddleOfVector() - 1;
    auto begin = childrenWeights.begin();
    if (begin != middleLeft)
      return getWeight(begin, middleLeft) + maxDifference;
    else
      return *begin + maxDifference;
  }

public: // публичные члены
  SeeSaw() = default;
  SeeSaw(const std::vector<int> &childrenWeights, const int &maxDifference)
      : childrenWeights(childrenWeights), maxDifference(maxDifference) {}
  int process() {
    sortChildrenWeight();
    std::cout << getLeftWeight() << '\n';
    std::cout << getRightWeight() << '\n';
    return getRightWeight() - getLeftWeight();
  }

  ~SeeSaw() = default;
};

std::vector<int> childrenWeights;
int maxDifference;

void userInput() {
  for (int childNumber = 1; childNumber < 4; ++childNumber) {
    int buffer = 0;
    std::cout << "Введите вес " << childNumber << "го ребенка: ";
    std::cin >> buffer;
    childrenWeights.push_back(buffer);
  }
  std::cout << "Ведите максимальую разницу в весах: ";
  std::cin >> maxDifference;
}

int main() {
  userInput();
  SeeSaw *seesaw = new SeeSaw(childrenWeights, maxDifference);
  std::unique_ptr<SeeSaw> seeSaw(new SeeSaw(childrenWeights, maxDifference));
  std::cout << seeSaw->process() << '\n';
}
