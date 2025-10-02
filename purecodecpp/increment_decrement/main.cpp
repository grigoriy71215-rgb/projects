#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

// Contents
long ten_to_the_power(unsigned char rank);
long reverse_digit(int &&digit);
int main();





long ten_to_the_power(unsigned char rank) {                     // сколько будет десять в степени rank
  long result = std::pow(10, rank);                             // std::pow(n, i), где n - основание(10), i - степень(rank)
  return result;                                                // результат функции
}

long reverse_digit(int &&digit) {                               // функция получения обратного числа (1244 -> 4421)
  long result_dec = 0;                                          // переменная для хранения обратного числа
  std::vector<int> decimalDigits;                               // массив разраядов digit
  while (digit != 0) {                                          // цикл нахождения разрядов числа digit
    int remainder = digit % 10;                                 // переменная для получения остатка от деления на 10 (10 - разрядность числа digit)
    decimalDigits.push_back(remainder);                         // добавляем полученнный разряд в массив
    digit /= 10;                                                // отсекаем младший разряд числа (он уже записан в decmalDigits)
  }
  std::cout << '\n';
  std::reverse(decimalDigits.begin(), decimalDigits.end());     // "переворачиваем массив" (последний элемент становится первым, первый - последним)
  unsigned char rank = 0;                                       // переменная разряда
  for (auto i : decimalDigits) {                                // цикл нахождения обратного числа
    result_dec += i * ten_to_the_power(rank);                   // ставим разряд на свое место
    ++rank;                                                     // единицы - десятки - сотни - тысячи
  }
  return result_dec;                                            // возвращает обратное число
}

int main() {
  int dec_digit = 5678;                                         // переменная для хранения данного числа
  std::cout << reverse_digit(std::move(dec_digit)) << '\n';    // вывод в терминал обратного числа dec_digit
t return 0;
}

