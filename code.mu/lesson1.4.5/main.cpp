#include <iostream>
#include <map>
#include <string>

enum class HourQuarter { FIRST, SECOND, THIRD, FOURTH, DEFAULT };

std::map<HourQuarter, std::string> hourQuarters = {
    {HourQuarter::FIRST, "первая"},
    {HourQuarter::SECOND, "вторая"},
    {HourQuarter::THIRD, "третья"},
    {HourQuarter::FOURTH, "четвертая"},
    {HourQuarter::DEFAULT, "невозможный вариант"}};

std::string getValueFromHourQuartersByKey(HourQuarter hourQuarter) {
  for (auto [key, value] : hourQuarters) {
    if (hourQuarter == key)
      return value;
  }
  return "";
}

std::string getHourQuarterByMinValue(int num) {
  if (num > 59 || num < 0)
    return getValueFromHourQuartersByKey(HourQuarter::DEFAULT);
  else if (num >= 0 && num < 15)
    return getValueFromHourQuartersByKey(HourQuarter::FIRST);
  else if (num >= 15 && num < 30)
    return getValueFromHourQuartersByKey(HourQuarter::SECOND);
  else if (num >= 30 && num < 45)
    return getValueFromHourQuartersByKey(HourQuarter::THIRD);
  else
    return getValueFromHourQuartersByKey(HourQuarter::FOURTH);
}

int main() {
  int num = 333;
  std::cout << "Четверть часа для " << num << " минут - "
            << getHourQuarterByMinValue(num) << '\n';
  return 0;
}
