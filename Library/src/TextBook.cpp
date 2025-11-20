#include "../include/TextBook.h"
std::string TextBook::display_info() const { // Определяет метод
  // display_info, который был объявлен как виртуальный в классе TextBook и
  // переопределяет метод из базового класса Book
  return Book::display_info() + "Subject: " + subject +
         "\nGrade Level: " + std::to_string(grade_level); // добавляет перевод
  // строки и текстовую метку
}
