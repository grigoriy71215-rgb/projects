#include <cstdio>
#include <cstdlib>

int main() {
  int *array = (int *)malloc(5 * sizeof(int)); // memory allocation - разметка памяти
  int *ptr = array; // указатель на начальный элемент массива
  for (int i = 0; i < 5; ++i) {
    array[i] = i;
  }
  for (int i = 0; i < 5; ++i) {
    printf("%d\n", *ptr);
    ++ptr;
  }
  free(array);
  return 0;
}
