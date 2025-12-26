#include <string>

void multiplyBy1024(float &prev) { prev *= 1024; }

std::string sizes[] = {"MB", "KB", "B"};

std::string &getById(int id) { return sizes[id]; }

int main(int argc, char *argv[]) {
  float size = 35.24;
  multiplyBy1024(size);
}
