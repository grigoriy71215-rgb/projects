int *iiii;

int main(int argc, char *argv[]) {
  const int i = 42;
  const int &ref_i = i;
  iiii = &ref_i;
  return 0;
}
