#include <utilities/system/CoutExtended.h>

int main(int argc, char *argv[]) {
  CoutExtended cout;
  cout.setPrecision(2).setDecades(true).blue() << 2435435.345435 << '\n';
  return 0;
}
