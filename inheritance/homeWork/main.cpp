#include "human.h"
#include <iostream>
#include <thread>

int main() {
  Human *human1 = new Human();
  human1->biting();
  std::this_thread::sleep_for(std::chrono::seconds(3));
  std::cout << human1->getIsMonster() << '\n';
  std::this_thread::sleep_for(std::chrono::seconds(5));
  std::cout << human1->getIsMonster() << '\n';
  std::this_thread::sleep_for(std::chrono::seconds(5));
  std::cout << human1->getIsMonster() << '\n';
  delete human1;
  return 0;
}
