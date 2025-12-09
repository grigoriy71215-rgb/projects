#include <iostream>
#include <map>
#include <string>

enum class Seasons { WINTER, SPRING, SUMMER, AUTUMN };

std::map<Seasons, std::string> seasons = {{Seasons::WINTER, "зима"},
                                          {Seasons::SPRING, "весна"},
                                          {Seasons::SUMMER, "лето"},
                                          {Seasons::AUTUMN, "осень"}};

std::string getSeason(Seasons season) {
  for (auto [key, value] : seasons) {
    if (key == season)
      return value;
  }
  return "";
}

std::string getSeasonByMonth(unsigned int month) {
  if (month == 0 || month > 12)
    return "non applicable";
  else if (month >= 1 && month < 3 || month == 12)
    return getSeason(Seasons::WINTER);
  else if (month >= 3 && month < 6)
    return getSeason(Seasons::SPRING);
  else if (month >= 6 && month < 9)
    return getSeason(Seasons::SUMMER);
  else
    return getSeason(Seasons::AUTUMN);
}

int main() {
  unsigned int num = 9;
  std::cout << getSeasonByMonth(num) << '\n';
  return 0;
}
