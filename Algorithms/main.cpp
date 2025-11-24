#include <Human.h>
#include <algorithm>
#include <execution>
#include <iostream>
#include <memory>
#include <vector>

void print(const std::vector<std::shared_ptr<Human>> &people) {
  std::for_each(people.cbegin(), people.cend(),
                [](std::shared_ptr<Human> human) {
                  std::cout << human->getName() << '\n';
                });
}

void addLastName(std::vector<std::shared_ptr<Human>> &&people) {
  std::for_each(std::execution::par, people.begin(), people.end(),
                [](std::shared_ptr<Human> people) {
                  if (people->getPol() == Human::Pol::male) {
                    people->setName(people->getName() + " Rybakin");
                  } else {
                    people->setName(people->getName() + " Rybakina");
                  }
                });
}

void sort(std::vector<std::shared_ptr<Human>> &&people) {
  std::sort(people.begin(), people.end(),
            [](std::shared_ptr<Human> one, std::shared_ptr<Human> two) {
              return one->getName() < two->getName();
            });
}

int main(int argc, char *argv[]) {
  std::vector<std::shared_ptr<Human>> people{
      std::make_shared<Human>("Grigory", 10, Human::Pol::male),
      std::make_shared<Human>("Polina", 13, Human::Pol::female),
      std::make_shared<Human>("Maya", 12, Human::Pol::female),
      std::make_shared<Human>("Alexey", 40, Human::Pol::male)};
  addLastName(std::move(people));
  sort(std::move(people));
  print(people);
  return 0;
}
