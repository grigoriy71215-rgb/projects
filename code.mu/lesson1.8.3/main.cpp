#include <iomanip>
#include <iostream>

void divideBy1024(double &num) { num /= 1024; }

const char *sizes[] = {"Kb", "Mb", "Gb"};

const char *&getSizeNameById(int id) { return sizes[id]; }

struct space_out : std::numpunct<char> {
  char do_thousands_sep() const override { return ' '; } // Разделитель - пробел
  std::string do_grouping() const override {
    return "\3"; // Группировать по 3 цифры
  }
};

int main(int argc, char *argv[]) {
  double b = 7435421243;
  std::cout << "Объем " << b << "Б в других единицах:\n";
  std::cout.imbue(std::locale(std::cout.getloc(), new space_out));
  for (int id = 0; id < 3; ++id) {
    divideBy1024(b);
    std::cout << std::fixed << std::setprecision(2);
    std::cout << " - " << b << ' ' << getSizeNameById(id) << '\n';
  }
  return 0;
}
