#include "./include/TextBook.h"
#include <iostream>
#include <memory>

int main(int argc, char *argv[]) {
  std::unique_ptr<Book> book =
      std::make_unique<TextBook>("title", "author", 2025, 1, "math", 7);
  std::cout << book->display_info() << '\n';
  return 0;
}
