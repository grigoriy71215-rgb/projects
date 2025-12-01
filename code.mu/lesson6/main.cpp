#include <iostream>
bool checkInRange(const int leftEdge, const int rightEdge, const int &num) {
  return leftEdge < num && num < rightEdge; // логическое И
}

bool getWorkDay(const std::string &day) {
  return day == "pn" || day == "vt" || day == "sr" || day == "cht" ||
         day == "pt"; // логическое ИЛИ
}

int main(int argc, char *argv[]) {
  std::cout << (getWorkDay("chtasdf") ? "yes" : "no") << '\n';
  return 0;
}
