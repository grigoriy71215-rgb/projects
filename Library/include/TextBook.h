#pragma once

#include "Book.h"
#include <string>

class TextBook final : public Book {
private:
  std::string subject;
  int grade_level;

public:
  TextBook() = default;
  TextBook(const std::string &title, const std::string &author, const int &year,
           bool is_available, const std::string &subject, int grade_level)
      : Book(title, author, year, is_available), subject(subject),
        grade_level(grade_level) {}
  ~TextBook() = default;

  virtual std::string display_info() const override;
};
