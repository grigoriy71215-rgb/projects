#include <iostream>                                     // для работы состандартным потоком вывода cout

unsigned char get_max_rank(long digit){                 // функция определяет скольки разрядное число которое хронится в digit
  unsigned char result = 0;                             // перенная в которой хронится результат
  while (digit != 0) {                                  // как только мы нашли число поделили на 10
    digit /= 10;                                        // digit = digit / 10 = boilerpl - bad
     ++result;
  }
  return result;                                        // возвращаем результат функции
}

int main (int argc, char *argv[]) {                     // отсюда начинается выполнение программы
  long digit = 1028937492874;                           // задание числа для нахождения разрядности
  unsigned char result = get_max_rank(digit);           // считает количество разрядов в числе 
  std::cout << (int)result << std::endl;                // выводим полученный результат на экран: 1 - число разрядное, 0 - число не разрядное
  return 0;                                             // код возврата 0 при удачном (без ошибок)
}
