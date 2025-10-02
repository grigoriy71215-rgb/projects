#include <iostream> // библиотека для стондартного потока вывода cout

// Пример
template <typename T> // template - шаблон, typename - имя типа
void functionName(T t) {
  std::cout << t << '\n';
}

// int main(int argc, char *argv[]) {
//   int i = 42;
//   char c = 'a';
//   float ff = 3.14;
//   templateAdd(i, 5);
//   functionName(&i);
//   functionName(c);
//   functionName(ff);
//   return 0;
// }

// Задание: написать шаблонную функцию, которая бы складывала два числа

// функция выбрасывает исключение при переполнении типа AddTypeName
template <typename AddTypeName> // template - шаблон, typename - имя типа
AddTypeName templateAdd(
    const AddTypeName &firstTerm, // функция templateAdd добоввляет шаблон
    const AddTypeName &secondTerm) {
  return firstTerm + secondTerm; // возвращяем сумму двух чисел
}

int main(int argc,
         char *argv[]) { // создаем функцию с которой начинает программа
  int i = 42;            // вводим значение i
  int j = 4;             // вводим значение j
  std::cout << templateAdd(i, j) << '\n'; // выводим их сумму
  return 0;                               // возвращяем
}
