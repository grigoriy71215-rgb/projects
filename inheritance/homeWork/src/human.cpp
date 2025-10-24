#include "human.h"

Human::Human() : Monster() {}
void Human::bite() { biting(); }
const std::string &Human::getIsMonster() {
  return static_cast<Monster *>(this)->getIsMonster();
}
