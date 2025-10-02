#include <stdio.h>

void switch_break() {
  int i = 5;
  switch (i) {
  case 5:
    printf("i equals to 5\n");
    break;
  case 4:
    printf("i equals to 4\n");
    break;
  default:
    printf("i is not equals to 4 or 5\n");
  }
  if (i == 5)
    printf("i equals to 5\n");
  else if (i == 4)
    printf("i equals to 4\n");
  else
    printf("i is not equals to 4 or 5\n");
}

void switch_non_break() {
  int i = 5;
  switch (i) {
  case 5:
    printf("i equals to 5\n");
  case 4:
    printf("i equals to 4\n");
    break;
  default:
    printf("i is not equals to 4 or 5\n");
  }
  if (i == 5)
    printf("i equals to 5\n");
  if (i == 4)
    printf("i equals to 4\n");
  printf("i is not equals to 4 or 5\n");
}

int main(int argc, char *argv[]) {
  switch_non_break();
  return 0;
}
