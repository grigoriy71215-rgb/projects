#include "Float.h"
#include <cmath>

Float::Float(const Float &other) {
  mantissa = other.mantissa;
  power = other.power;
}

Float::Float(Float &&other) noexcept {
  mantissa = other.mantissa;
  power = other.power;
  other.mantissa = 0;
  other.power = 0;
}

Float &Float::operator=(const Float &other) {
  mantissa = other.mantissa;
  power = other.power;
  return *this;
}

Float &Float::operator=(Float &&other) noexcept {
  mantissa = other.mantissa;
  power = other.power;
  other.mantissa = 0;
  other.power = 0;
  return *this;
}

void Float::set(int mantissa, int power) {
  this->mantissa = mantissa;
  this->power = power;
}

void Float::setMantissa(int mantissa) { this->mantissa = mantissa; }

void Float::setPower(int power) { this->power = power; }

int Float::getMantissa() const { return mantissa; }

int Float::getPower() const { return power; }

float Float::getFloat() const { return mantissa * std::pow(10, power); }
