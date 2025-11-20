#include "./include/FictionBook.h" // для членов классa
// FictionBook.h
#include "./include/TextBook.h" // для членов классa
// FictionBook.h
#include <algorithm> // для std::copy и std::for_each
#include <execution> // для std::execution::par (параллельное выполнение)
#include <iostream>  // для std::cout
#include <memory>    // для std::shared_ptr и std::make_shared
#include <vector>    // для std::vector

void f(std::unique_ptr<Book> book) {}

int main(int argc, char *argv[]) {
  std::vector<std::shared_ptr<Book>> library; // инициализация массива книг
  std::shared_ptr<Book> book = std::make_shared<TextBook>(
      "title", "author", 2025, 1, "math", 7); // указатель на книгу
  // указатель на TextBook
  library.push_back(std::move(book)); // добавление книги в массив
  book = std::make_shared<FictionBook>("title1", "author1", 2025, 1, "sci-fi",
                                       14);  // указатель на FictionBook
  library.push_back(std::move(book));        // добавление книги в массив
  std::vector<std::shared_ptr<Book>> author; // книги определенного автора
  std::copy_if(std::execution::par, library.cbegin(), library.cend(),
               std::back_inserter(author), [book](std::shared_ptr<Book> book1) {
                 return book1->getAuthor() == "author";
               }); // ищем книги по автору author из library и копируем их в
                   // массив author
  std::for_each(std::execution::par, author.cbegin(), author.cend(),
                [](std::shared_ptr<Book> book) {
                  std::cout << book->getTitle() << '\n';
                }); // для каждой полученной книги (for_each) выводим в ст.
                    // поток вывода название этой книги
  return 0;
}
