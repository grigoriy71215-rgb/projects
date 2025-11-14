#pragma once

#include <Book.h>
#include <string>
class TextBook final : public Book {
private:
  std::string subject;
  int grade_level;

public:
  Book(const std::string &subjectd, const int &year, bool is_available)
      : title(title), author(author), year(year), is_available(is_available) {}
};
