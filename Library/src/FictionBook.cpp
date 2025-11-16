#include "../include/FictionBook.h"

std::string FictionBook::display_info() const {
  return Book::display_info() + "Genre: " + genre +
         "\nAge rating: " + std::to_string(age_rating);
}
