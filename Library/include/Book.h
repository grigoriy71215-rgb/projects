#pragma once

#include <string> // библиотека данных для потока вывода string

class Book { // Объявление базового класса
protected: // Объявляет, что следующие члены класса будут доступны внутри самого
           // класса и в классах-наследниках, но не извне
  std::string title;  // название книги
  std::string author; // строка для хранения имени автора
  int year;           // целое число для хранения года издания
  bool is_available;  // логический флаг, указывающий доступность книги
  Book() = default;   // дефолтный конструктор

public:
  Book(const std::string &title, const std::string &author, const int &year,
       bool is_available)
      : title(title), author(author), year(year), is_available(is_available) {
  } // Объявляет конструктор, принимающий четыре параметра для инициализации
    // всех полей книги.
  virtual std::string display_info() const; // виртуальный метод display_info
  virtual ~Book() = default;                // виртуальный диструктор

  virtual const std::string &getTitle() const { return title; }
  virtual const std::string &getAuthor() const {
    return author;
  } // Объявляет виртуальные методы для получения названия и автора книги.
    // Возвращают константные ссылки на соответствующие поля
};
