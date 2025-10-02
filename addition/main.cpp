#include <cstdlib>
#include <iostream>

void userInput(unsigned int&& firstTerm, unsigned int&& secondTerm) {               // move semantics
  std::cout << "введите первое число: ";                                            // comment to enter first term of sum
  std::cin >> firstTerm;                                                            // input first term of sum in ui variable
  std::cout << "введите второе число: ";                                            // comment to enter second term of sum
  std::cin >> secondTerm;
}

void argumentImput(unsigned int&& firstTerm, unsigned int&& secondTerm, char* argv[]) {
  firstTerm = atoi(argv[1]);
  secondTerm = atoi(argv[2]);
}

void printResult(const unsigned int& firstTerm, const unsigned int& secondTerm) {
  std::cout << "результат сложения " << firstTerm << " и " << secondTerm << " равен: ";            // comment to result output of sum
  std::cout << firstTerm + secondTerm << std::endl;                                                // output result of sum
}

int main(int argc, char* argv[]) {                                                                        // Main function: start point of the program
  unsigned int firstTerm = 5;                                                       // firstTerm - first term of sum
  unsigned int secondTerm = 8;                                                      // secondTerm - second term of sum
  if (argc != 3) {
    userInput(std::move(firstTerm), std::move(secondTerm));
  } else {
    argumentImput(std::move(firstTerm), std::move(secondTerm), argv);
  }                                                                                   // input second term of sum in iu variable
  printResult(firstTerm, secondTerm);
  return 0;                                                                           // return program code is zero (successfully)
}
