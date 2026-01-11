#include <iostream>
void divideByTwo(float &num) { num /= 2; }

int countOfDivisions(float num) {
  int counter = 0;
  while (num >= 10) {
    std::cout << "old num: " << num;
    divideByTwo(num);
    ++counter;
    std::cout << "; counter: " << counter << "; num after division: " << num
              << '\n';
  }
  return counter;
}

int main(int argc, char *argv[]) {
  float num = 2347632;
  std::cout << "------------------------\n";
  int count = countOfDivisions(num);
  std::cout << "------------------------\n";
  std::cout << "Количество итераций при делении " << num << " на 2 равно "
            << count << '\n';
  return 0;
}
