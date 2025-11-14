#include "../include/Book.h"

std::string Book::display_info() const {
  return "Title: " + title + '\n' + "Author: " + author + '\n' +
         "Year: " + std::to_string(year) + '\n' +
         "Is available: " + std::to_string(is_available) + '\n';
}
