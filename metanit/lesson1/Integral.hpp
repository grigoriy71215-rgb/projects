#pragma once

#include <exception>
#include <iostream>
#include <type_traits>

template <typename IntegralType> class Integral {
private:
  IntegralType value;

  IntegralType assertValue(IntegralType value) {
    static_assert(std::is_integral_v<IntegralType>,
                  "Параметр шаблона должен быть целым числом!");
    if constexpr (!std::is_integral_v<IntegralType>) {
      std::cout << typeid(IntegralType).name() << " is not an integral\n";
      std::terminate();
    }
    return value;
  }

public:
  Integral(IntegralType value) : value(assertValue(value)) {}

  IntegralType getValue() const { return value; }
  void setValue(IntegralType value) { this->value = value; }
};
