#include "Human.h"

Human::Human(const std::string &name, int age, Pol pol)
    : name(name), age(age), pol(pol) {}

Human::Human(const Human &other) noexcept {
  name = other.name;
  age = other.age;
  pol = other.pol;
}

Human &Human::operator=(const Human &other) noexcept {
  name = other.name;
  age = other.age;
  pol = other.pol;
  return *this;
}

std::string Human::getName() const noexcept { return name; }

void Human::setName(const std::string &name) { this->name = name; }

void Human::setAge(int age) { this->age = age; }

Human::Pol Human::getPol() const noexcept { return pol; }
