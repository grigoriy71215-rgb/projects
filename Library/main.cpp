#include "./include/FictionBook.h"
#include "./include/TextBook.h"
#include <algorithm>
#include <execution>
#include <iostream>
#include <memory>
#include <vector>

void f(std::unique_ptr<Book> book) {}

int main(int argc, char *argv[]) {
  std::vector<std::shared_ptr<Book>> library;
  std::shared_ptr<Book> book =
      std::make_shared<TextBook>("title", "author", 2025, 1, "math", 7);
  library.push_back(std::move(book));
  book =
      std::make_shared<FictionBook>("title1", "author1", 2025, 1, "sci-fi", 14);
  library.push_back(std::move(book));
  std::vector<std::shared_ptr<Book>> author;
  std::copy_if(std::execution::par, library.cbegin(), library.cend(),
               std::back_inserter(author), [book](std::shared_ptr<Book> book1) {
                 return book1->getAuthor() == "author";
               });
  std::for_each(std::execution::par, author.cbegin(), author.cend(),
                [](std::shared_ptr<Book> book) {
                  std::cout << book->getTitle() << '\n';
                });
  return 0;
}
