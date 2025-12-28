#include <iostream>
#include <stdexcept>
#include <string>

// @throws std::invalid_argument exception
union A {
  int i;
  double d;
};

bool isEqualFirstAndLast(const std::string &str1, const std::string &str2) {
  if (str1.length() == 0)
    throw std::invalid_argument("Первая строка - нулевая");
  if (str2.length() == 0)
    throw std::invalid_argument("Вторая строка нулевая");
  return *--str1.end() == *str2.begin();
}

int main(int argc, char *argv[]) {
  std::string str1 = "asdkflj";
  std::string str2 = "";
  bool res = false;
  try {
    res = isEqualFirstAndLast(str1, str2);
  } catch (std::invalid_argument e) {
    std::cout << e.what() << '\n';
    std::cout << "Программа завершена с ошибкой!\n";
    return 1;
  }
  std::cout << "Последняя буква слова " << str1 << (res ? "" : " не")
            << " совпадает с первой буквой слова " << str2 << '\n';
  return 0;
}
