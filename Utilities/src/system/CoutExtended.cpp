#include "system/CoutExtended.h"
#include <cmath>
#include <iomanip>
#include <sstream>

CoutExtended::CoutExtended(std::ostream &os)
    : out(os), width(0), precision(6), showDecades(false), fillChar(' '),
      fmtFlags(os.flags()), colorCode("") {}

CoutExtended::~CoutExtended() { out.flags(fmtFlags); }

std::string CoutExtended::getResetColor() const { return "\033[0m"; }

std::string CoutExtended::applyColor(const std::string &text) const {
  if (!colorCode.empty()) {
    return colorCode + text + getResetColor();
  }
  return text;
}

std::string CoutExtended::formatWithDecades(double value) const {
  std::stringstream ss;
  ss << std::fixed << std::setprecision(precision);

  long long intPart = static_cast<long long>(std::abs(value));
  std::string intStr = std::to_string(intPart);

  if (showDecades && intStr.length() > 3) {
    std::string formatted;
    int count = 0;
    for (int i = intStr.length() - 1; i >= 0; i--) {
      formatted = intStr[i] + formatted;
      count++;
      if (count % 3 == 0 && i > 0) {
        formatted = " " + formatted;
      }
    }
    intStr = formatted;
  }

  double fracPart = std::abs(value) - static_cast<long long>(std::abs(value));
  std::string fracStr;
  if (precision > 0) {
    ss << fracPart;
    std::string temp = ss.str();
    fracStr = temp.substr(temp.find('.') + 1);
  }

  std::string result = (value < 0 ? "-" : "") + intStr;
  if (precision > 0) {
    result += "." + fracStr;
  }

  return result;
}

std::string CoutExtended::formatWithDecades(long long value) const {
  std::string intStr = std::to_string(std::abs(value));

  if (showDecades && intStr.length() > 3) {
    std::string formatted;
    int count = 0;
    for (int i = intStr.length() - 1; i >= 0; i--) {
      formatted = intStr[i] + formatted;
      count++;
      if (count % 3 == 0 && i > 0) {
        formatted = " " + formatted;
      }
    }
    intStr = formatted;
  }

  return (value < 0 ? "-" : "") + intStr;
}

CoutExtended &CoutExtended::operator<<(double value) {
  std::string formatted = formatWithDecades(value);
  formatted = applyColor(formatted);

  if (width > 0) {
    out << std::setw(width) << std::setfill(fillChar) << formatted;
  } else {
    out << formatted;
  }

  return *this;
}

CoutExtended &CoutExtended::operator<<(long long value) {
  std::string formatted = formatWithDecades(value);
  formatted = applyColor(formatted);

  if (width > 0) {
    out << std::setw(width) << std::setfill(fillChar) << formatted;
  } else {
    out << formatted;
  }

  return *this;
}

CoutExtended &CoutExtended::operator<<(const std::string &str) {
  std::string formatted = applyColor(str);

  if (width > 0) {
    out << std::setw(width) << std::setfill(fillChar) << formatted;
  } else {
    out << formatted;
  }
  return *this;
}

CoutExtended &CoutExtended::operator<<(const char *str) {
  std::string formatted = applyColor(std::string(str));

  if (width > 0) {
    out << std::setw(width) << std::setfill(fillChar) << formatted;
  } else {
    out << formatted;
  }
  return *this;
}

CoutExtended &CoutExtended::operator<<(char ch) {
  out << ch;
  return *this;
}

CoutExtended &CoutExtended::operator<<(std::ostream &(*manip)(std::ostream &)) {
  out << manip;
  return *this;
}

CoutExtended &CoutExtended::setWidth(int w) {
  width = w;
  return *this;
}

CoutExtended &CoutExtended::setPrecision(int p) {
  precision = p;
  return *this;
}

CoutExtended &CoutExtended::setDecades(bool enable) {
  showDecades = enable;
  return *this;
}

CoutExtended &CoutExtended::setFill(char ch) {
  fillChar = ch;
  return *this;
}

CoutExtended &CoutExtended::setColor(const std::string &hexColor) {
  if (hexColor.length() == 7 && hexColor[0] == '#') {
    int r, g, b;
    sscanf(hexColor.c_str() + 1, "%02x%02x%02x", &r, &g, &b);
    colorCode = "\033[38;2;" + std::to_string(r) + ";" + std::to_string(g) +
                ";" + std::to_string(b) + "m";
  }
  return *this;
}

CoutExtended &CoutExtended::setColor(int r, int g, int b) {
  colorCode = "\033[38;2;" + std::to_string(r) + ";" + std::to_string(g) + ";" +
              std::to_string(b) + "m";
  return *this;
}

CoutExtended &CoutExtended::resetColor() {
  colorCode = "";
  return *this;
}

CoutExtended &CoutExtended::red() {
  colorCode = "\033[38;2;255;0;0m";
  return *this;
}

CoutExtended &CoutExtended::green() {
  colorCode = "\033[38;2;0;255;0m";
  return *this;
}

CoutExtended &CoutExtended::blue() {
  colorCode = "\033[38;2;0;0;255m";
  return *this;
}

CoutExtended &CoutExtended::yellow() {
  colorCode = "\033[38;2;255;255;0m";
  return *this;
}

CoutExtended &CoutExtended::magenta() {
  colorCode = "\033[38;2;255;0;255m";
  return *this;
}

CoutExtended &CoutExtended::cyan() {
  colorCode = "\033[38;2;0;255;255m";
  return *this;
}

CoutExtended &CoutExtended::white() {
  colorCode = "\033[38;2;255;255;255m";
  return *this;
}

CoutExtended &CoutExtended::black() {
  colorCode = "\033[38;2;0;0;0m";
  return *this;
}

void CoutExtended::reset() {
  width = 0;
  precision = 6;
  showDecades = false;
  fillChar = ' ';
  colorCode = "";
}
