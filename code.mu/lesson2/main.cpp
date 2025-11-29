#include <iostream>
#include <iterator>
#include <string>

int getDistance(const std::string &line) {
  return std::distance(line.begin(), line.end());
}

int getLength(const std::string &line) { return line.length(); }

int getSize(const std::string &line) { return line.size(); }

int main(int argc, char *argv[]) {
  std::cout << getDistance("string") << '\n';
  std::cout << getLength("string") << '\n';
  std::cout << getSize("string") << '\n';
  return 0;
}
