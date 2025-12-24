#include <initializer_list>
#include <iostream>
#include <string>

int getSumOfStrings(std::initializer_list<std::string> stril) {
  // for (int i = 0; i < 10; ++i) {
  int sum = 0;
  for (std::initializer_list<std::string>::iterator it = stril.begin();
       it != stril.end(); ++it) {
    int currentValue = std::stoi(*it);
    sum += currentValue;
  }
  return sum;
}

int main(int argc, char *argv[]) {
  std::string str1 = "123";
  std::string str2 = "456";
  std::string str3 = "789";
  std::cout << "Результат сложения значений строк \"" << str1 << "\", \""
            << str2 << "\" и \"" << str3 << "\" как целых чисел равен "
            << getSumOfStrings({str1, str2, str3}) << '\n';
  return 0;
}
