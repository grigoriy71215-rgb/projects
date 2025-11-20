#include "../include/Book.h" // библиотека данных для потока вывода Book

std::string
Book::display_info() const { // Определяет (реализует) метод display_info,
                             // который был объявлен в классе Book
  return "Title: " + title + '\n' + "Author: " + author + '\n' +
         "Year: " + std::to_string(year) + '\n' +
         "Is available: " + (is_available ? "yes" : "no") + '\n'; //  Добавляет
  //  информацию о доступности книги.
}
