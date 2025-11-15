#include "../include/TextBook.h"

std::string TextBook::display_info() const {
  return Book::display_info() + "Subject: " + subject +
         "\nGrade Level: " + std::to_string(grade_level);
}
