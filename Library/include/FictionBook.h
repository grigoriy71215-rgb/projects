#pragma once

#include "Book.h" // содержимое заголовочного файла Book.h
#include <string> // библиотека данных для потока вывода string

class FictionBook final
    : public Book {  // Объявляет новый класс с именем FictionBook
private:             // скрытые члены класса
  std::string genre; // жанр класса
  int age_rating;    // возрастной рейтинг

public:                    // открытые члены класса
  FictionBook() = default; // онструктор по умолчанию для класса FictionBook
  FictionBook(const std::string &title, const std::string &author,
              const int &year, bool is_available, const std::string &genre,
              const int &age_rating)
      : Book(title, author, year, is_available), genre(genre),
        age_rating(age_rating) {}   // конструктор
  virtual ~FictionBook() = default; // виртуальный деструктор
  virtual std::string
  display_info() const override; // виртуальный метод display_info
};
