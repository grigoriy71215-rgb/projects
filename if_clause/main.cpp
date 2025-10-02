/* Задача: сделать пользовательский ввод часов дня. Программа должна выводить
 * время суток: если час от 23 до 7 не включительно - ночь если час от 7 до 11
 * не включительно - утро если час от 11 до 18 не включительно - день если час
 * от 18 до 23 не включительно - вечер */

#include <iostream>

int getHourOfTheDay() {
  int hour;
  std::cout << "введите час суток: ";
  std::cin >> hour;
  return hour;
}

int printPartOfTheDay(int hour) {
  if (hour < 0)
    return 1;
  else if (hour > 24)
    return 2;
  else if (hour >= 7 && hour < 11)
    std::cout << "утро\n";
  else if (hour >= 11 && hour < 18)
    std::cout << "день\n";
  else if (hour >= 18 && hour < 23)
    std::cout << "вечер\n";
  else if (hour >= 23 || hour == 24)
    std::cout << "ночь\n";
  else if (hour >= 0 && hour < 7)
    std::cout << "ночь\n";
  return 0;
}

int main(int argc, char *argv[]) {
  printPartOfTheDay(getHourOfTheDay());
  return 0;
}
