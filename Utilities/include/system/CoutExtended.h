#pragma once

#include <iostream>
#include <string>

class CoutExtended {
private:
  std::ostream &out;
  int width;
  int precision;
  bool showDecades;
  char fillChar;
  std::ios_base::fmtflags fmtFlags;
  std::string colorCode;

  std::string formatWithDecades(double value) const;
  std::string formatWithDecades(long long value) const;
  std::string getResetColor() const;
  std::string applyColor(const std::string &text) const;

public:
  CoutExtended(std::ostream &os = std::cout);
  ~CoutExtended();

  CoutExtended &operator<<(double value);
  CoutExtended &operator<<(long long value);
  CoutExtended &operator<<(const std::string &str);
  CoutExtended &operator<<(const char *str);
  CoutExtended &operator<<(char ch);
  CoutExtended &operator<<(std::ostream &(*manip)(std::ostream &));

  CoutExtended &setWidth(int w);
  CoutExtended &setPrecision(int p);
  CoutExtended &setDecades(bool enable);
  CoutExtended &setFill(char ch);
  void reset();

  CoutExtended &setColor(const std::string &hexColor);
  CoutExtended &setColor(int r, int g, int b);
  CoutExtended &resetColor();

  CoutExtended &red();
  CoutExtended &green();
  CoutExtended &blue();
  CoutExtended &yellow();
  CoutExtended &magenta();
  CoutExtended &cyan();
  CoutExtended &white();
  CoutExtended &black();
};
