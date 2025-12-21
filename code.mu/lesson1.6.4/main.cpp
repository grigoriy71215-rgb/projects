// 1МБ = 1024кБ
// 1кБ = 1024Б
//
#include <iostream>

int getBytesFromMB(int megaBytes) { return megaBytes * 1024 * 1024; }

int main(int argc, char *argv[]) {
  int megaBytes = 35;
  std::cout << "Количество байт в " << megaBytes << " равно "
            << getBytesFromMB(megaBytes) << '\n';
  return 0;
}
