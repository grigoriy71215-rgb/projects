int expression(int (*func)(int, int), int var1, int var2) {
  return func(var1, var2);
}

int _add(int var1, int var2) { return var1 + var2; }
int _dec(int var1, int var2) { return var1 - var2; }
int _mult(int var1, int var2) { return var1 * var2; }
int _div(int var1, int var2) { return var1 / var2; }

float _add2(int var1, float var2) { return var1 + var2; }

// (1 + 2) * (3 + 4)
int call() {
  return expression(_mult, expression(_add, 1, 2), expression(_add, 3, 4));
}

int call2() { return expression(_add2, 2, 2); }

int main(int argc, char *argv[]) {
  call();
  call2();
  return 0;
}
