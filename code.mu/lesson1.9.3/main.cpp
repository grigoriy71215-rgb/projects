#include <iostream>

int getSecondsOfDays(int second) {
  int seconds = 60;
  int minutes = 60;
  int hours = 24;
  return seconds * minutes * hours * second;
}

int main(int argc, char *argv[]) {
  int days = 10;
  std::cout << "В " << days << " сутках содержится " << getSecondsOfDays(days)
            << " секунд " << '\n';
  return 0;
}
