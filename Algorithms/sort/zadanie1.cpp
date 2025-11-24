#include <algorithm>
#include <iostream>
#include <vector>

struct Person {
  std::string name;
  int age;
  double salary;
};

std::vector<Person> people = {
    {"Alice", 25, 50000}, {"Bob", 30, 45000}, {"Charlie", 22, 60000}};

void sortAge() {
  std::sort(people.begin(), people.end(),
            [](const Person &a, const Person &b) { return a.age < b.age; });
}

void print() {
  std::for_each(people.cbegin(), people.cend(), [](const Person &person) {
    std::cout << "имя: " << person.name << ", возраст: " << person.age
              << ", зарплата: " << person.salary << '\n';
  });
}

void sortSalary() {
  std::sort(people.begin(), people.end(), [](const Person &a, const Person &b) {
    return a.salary < b.salary;
  });
}

void sortName() {
  std::sort(people.begin(), people.end(),
            [](const Person &a, const Person &b) { return a.name < b.name; });
}

int main(int argc, char *argv[]) {
  // Отсортировать по возрасту (по возрастанию)
  // sortAge();
  // print();
  // Отсортировать по зарплате (по убыванию)
  // sortSalary();
  // print();
  // Отсортировать по имени (лексикографически)
  sortName();
  print();
  return 0;
}
