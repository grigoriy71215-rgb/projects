/*типы данных подсвечены желтым,
 * названия функций подсвечены синим,
 * переменные из параметров функции подсвечены красным,
 * переменные, объявленные в функции, подсвечены белым,
 * числа подсвечены оранжевым,
 * библиотеки данных подсвечены зеленым,*/
/*
 * Задача: преобразовать десятичное число в двоичное
 */
#include <cmath>     // она нам нужна С #include <iostream> #include <stdexcept>
#include <iostream>  //
#include <stdexcept> // для работы с std::runtime_error

long ten_to_the_power(unsigned char rank) {           // переменная rank, тип данных unsigned char
  long result = std::pow(10, rank); // функция, переменная rank
  return result;                    // результат проверки
}

long dec_to_bin_positive(int dec_digit) {      // переменная dec_digit, тип данных int
  long result_bin = 0;    //
  unsigned char rank = 0;
  while (dec_digit != 0) {
    bool remainder = dec_digit % 2; // переменная remainder, тип данных bool
    result_bin += remainder * ten_to_the_power(rank); // функция
    ++rank;
    dec_digit /= 2; // переменная dec_digit
  }
  return result_bin;
}

long dec_to_bin_negative(
    int dec_digit) { // функция, переменная dec_digit, тип данных int
  long result_bin = 0;
  return result_bin;
}

long get_maximum(
    unsigned char rank_number) { // функция, переменная rank_number, тип данных
                                 // unsigned char
  if (rank_number <= 0 || rank_number >= 20) // переменная rank_number
    throw std::runtime_error("rank is out of range");
  long result = 0;
  unsigned char counter = 0;
  while (counter < rank_number) { // переменная rank_number
    if (result == 0) {
      result = 1;
    } else {
      result *= 10;
      result += 1;
    }
    // result = (result > 0 ? result * 10 : result) + 1;
    ++counter;
  }
  return result;
}

long reverse(
    long result_bin) { // функция, переменная result_bin, тип данных long
  long result_reverse = 0;
  return result_reverse;
}

long dec_to_bin(int dec_digit) { // функция, переменая dec_digit
  long result_bin = 0;
  if (dec_digit > 0)
    result_bin =
        dec_to_bin_positive(dec_digit); // функция, переменная dec_digit
  else {
    result_bin =
        dec_to_bin_positive(0 - dec_digit); // функция, переменная dec_digit
    long maximum = get_maximum(19);         // функция, тип данных long
    result_bin = maximum - result_bin;
  }
  return result_bin;
}

// функция сложения двух бинарных чисел
long add_bin_numbers(long bin_number1,
                     long bin_number2) { // функция, тип данных long
  long bin_result = bin_number1;

  return bin_result;
}

long divide_to_five(long number) { return number / 5; }

int main(int argc, char *argv[]) { // тип данных int, char
  long number = 15;
  std::cout << divide_to_five(number) << '\n';
  return 0;
}
