#include <stdio.h>

int main(int argc, char *argv[]) {
  int *i;
  *i = 5;
  printf("%d\n", *i);
  char *ch;
  *ch = 'a';
  printf("%s\n", *ch);
  return 0;
}
