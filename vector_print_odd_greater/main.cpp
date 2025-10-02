// Задача: дан массив чисел { 100, 200, 301, 403, 500, 663, 771 } Вывести
// количество нечетных чисел, больших, чем введет пользователь. Для удобства
// пользователя, сначала требуется вывести весь массив на экран

#include <iostream> // библиотека данных для потока вывода cout
#include <vector>   // библиотека данных для потока вывода vector

std::vector<int> numbers = {100, 200, 301, 403, 500, 663, 771}; // данный массив

int main(int argc, char *argv[]) { // функция с которой начинает программа
  for (auto it = numbers.begin(); it != numbers.end(); ++it) { // цикл for
    std::cout << *it << " ";                                   // выводим *it
  }
  std::cout << '\n'; // переход на следующую строку
  int chislo = 0;    // присваеваем переменной chislo прервоночальное значение
  std::cout << "Введите число: "; // вводим число на экран
  std::cin >> chislo;             // выводим на экран прервоночальное число
  int kolichestvo =
      0; // присваеваем переменной kolichestvo прервоночальное значение
  for (auto it = numbers.begin(); it != numbers.end(); ++it) { // цикл for
    int znatchenie = *it;           // присваеваем переменной znatchenie *it
    int tchastnoe = znatchenie / 2; // проверяем на не четность
    bool ostatok = znatchenie - 2 * tchastnoe; // получаем остаток
    if (ostatok == 1 && znatchenie > chislo)   // остаток = 1
      ++kolichestvo;
  }
  std::cout << kolichestvo
            << '\n'; // выводим количество нечетных элементов на экран
  return 0;
}
