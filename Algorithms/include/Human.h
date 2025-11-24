#pragma once

#include <string>

class Human final {
private:
  std::string name;
  int age;

public:
  enum Pol { male, female };
  Human() = default;
  Human(const std::string &name, int age, Pol pol);
  Human(const Human &other) noexcept;
  ~Human() = default;

  Human &operator=(const Human &other) noexcept;

  std::string getName() const noexcept;
  Pol getPol() const noexcept;

  void setAge(int age);
  void setName(const std::string &name);

private:
  Pol pol;
};
