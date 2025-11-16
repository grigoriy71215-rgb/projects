#pragma once

#include "Book.h"
#include <string>

class FictionBook final : public Book {
private:
  std::string genre;
  int age_rating;

public:
  FictionBook() = default;
  FictionBook(const std::string &title, const std::string &author,
              const int &year, bool is_available, const std::string &genre,
              const int &age_rating)
      : Book(title, author, year, is_available), genre(genre),
        age_rating(age_rating) {}
  virtual ~FictionBook() = default;
  virtual std::string display_info() const override;
};
