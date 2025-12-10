#pragma once

#include <cmath>
class Float {
protected:
  Float() = default;

  int mantissa = 0;
  int power = 0;

public:
  Float(int mantissa, int power) : mantissa(mantissa), power(power) {}

  Float(const Float &other);
  Float(Float &&other) noexcept;
  Float &operator=(const Float &other);
  Float &operator=(Float &&other) noexcept;
  void set(int mantissa, int power);
  void setMantissa(int mantissa);
  void setPower(int power);

  int getMantissa() const;
  int getPower() const;
  float getFloat() const;

  virtual ~Float() = default;
};
