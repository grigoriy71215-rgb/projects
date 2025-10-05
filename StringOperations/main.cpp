#include "./include/OccuranciesGetter.h"
#include <iostream>

int main(int argc, char *argv[]) {
  OccuranciesGetter *occuranciesGetter =
      new OccuranciesGetter("Test test test", "test");
  std::cout << occuranciesGetter->getCountOfOccurancies() << '\n';
  delete occuranciesGetter;
  return 0;
}
