#pragma once

#include <string>

class Book {
protected:
  std::string title;
  std::string author;
  int year;
  bool is_available;
  Book() = default;

public:
  Book(const std::string &title, const std::string &author, const int &year,
       bool is_available)
      : title(title), author(author), year(year), is_available(is_available) {}
  virtual std::string display_info() const;
  virtual ~Book() = default;

  virtual const std::string &getTitle() const { return title; }
  virtual const std::string &getAuthor() const { return author; }
};
