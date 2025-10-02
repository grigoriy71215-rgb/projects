/*
Задача: Дана строка, вывести 1й, 2й и 4й символы 
 */ 

#include <iostream>
void print(std::string&& myString) {
  std::cout << myString[0] << '\n';
  std::cout << myString[1] << '\n';
  std::cout << myString[3] << '\n';
}

/*
Задача: написать функцию поиска символа в строке
*/



int main (int argc, char *argv[]) {
  std::string myString = "abcdefg";
  print(std::move(myString));
  return 0;
}
