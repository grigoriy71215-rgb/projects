#include "../include/FictionBook.h"

std::string FictionBook::display_info() const { // Определяет метод
  // display_info, который был объявлен как виртуальный в классе TextBook и
  // переопределяет метод из базового класса Book
  return Book::display_info() + "Genre: " + genre +
         "\nAge rating: " + std::to_string(age_rating); // Начинает формирование
  // возвращаемой строки
}
