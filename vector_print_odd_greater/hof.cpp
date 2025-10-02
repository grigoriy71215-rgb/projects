// HOF - high order function - функция высокого порядка
#include <iostream> // библиотека данных для потока вывода соut
#include <vector>   // библиотека данных для потока вывода vector

int enumerate(std::vector<int> &&vint, //
              void (*prefunc)(void),   //
              int (*func)(int, int,
                          int),     // указатель на функцию трех аргументов
                                    // типа int, возвращающую int
              int variable = 0,     // необязательный аргумент функции,
                                    // в случае, если он не задан, значение
                                    // аргумента равно 0
              int userNumber = 0) { // необязательный аргумент функции,
                                    // в случае, если он не задан, значение
                                    // аргумента равно 0
  prefunc();                        //
  for (auto it : vint) { // цикл проходит по каждому элементу контейнера
    variable = func(it, variable, userNumber); // вызов функции по указателю и
    // передача полученного значения в variable
  }
  return variable; // возвращаем variable
}

void unused() {} // пустая функция, которая не принемает аргументов и не
// возвращает значения void

void printCaption() {                        // напречатать следующий массив
  std::cout << "Задан следующий массив: \n"; // задаем следующий массив
}

int printData(int number, int,
              int) {          // вывести number
  std::cout << number << ' '; // выводим число
  return 0;                   // возвращаем 0
}

int countOddGreaterThan(int number, int sum, int userNumber) { // считает
  // количество элементов
  if (number % 2 == 1 && number > userNumber) // проверяем чотное ли число
    ++sum;                                    // оператор инкремента
  return sum;                                 // возвращаем sum
}

int userInput() {                   // вывести число
  std::cout << "\nВведите число: "; // вводим число
  int userNumber = 0; // обьявление целочисленной переменной с именем userNumber
  std::cin >> userNumber; // cинтаксис
  return userNumber;      // выводим userNumber
}

void printResult(int userNumber, int countOfOddGreaterThan) {
  // функция двух аргументов типа int
  std::cout << "Нечетных больше " << userNumber << ": " << countOfOddGreaterThan
            << '\n'; // выводим нечетные числа
}

int main(int argc, char *argv[]) { // функция с которой начинаится програма
  std::vector<int> vint = {1, 3, 5, 7, 9}; // задаем массив
  enumerate(std::move(vint), printCaption,
            printData);         // вызов функции enumerate
  int userNumber = userInput(); // присаеваем значение одной переменной
  int countOfOddGreaterThan =
      enumerate(std::move(vint), unused, countOddGreaterThan, 0, userNumber);
  // вызов функции enumerate
  printResult(userNumber,
              countOfOddGreaterThan); // вызов метода который принемает
  // два параметра
  return 0; // выводим 0
}
