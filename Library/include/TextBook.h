#pragma once

#include "Book.h"
#include <string>

class TextBook final : public Book { // класс с именем TextBook
private:                             // cкрытые члены класса
  std::string subject;               // предмет книги
  int grade_level;                   // класс

public:                 // открытые члены класса
  TextBook() = default; // конструктор по умолчанию
  TextBook(const std::string &title, const std::string &author, const int &year,
           bool is_available, const std::string &subject, int grade_level)
      : Book(title, author, year, is_available), subject(subject),
        grade_level(grade_level) {} // конструктор
  virtual ~TextBook() = default;    // виртуальный детсруктор

  virtual std::string
  display_info() const override; // виртуальный метод display_info
};
