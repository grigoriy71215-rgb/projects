#include "monster.h"

std::chrono::duration<double> Monster::getBiteDuration() const {
  return std::chrono::system_clock::now() - biteDate;
}

void Monster::biting() { biteDate = std::chrono::system_clock::now(); }

const std::string &Monster::getIsMonster() {
  auto duration = getBiteDuration().count();
  if (duration < 5 || duration >= 10000)
    isMonster = 0;
  else if (duration < 10)
    isMonster = 1;
  else if (duration >= 10 && duration < 10000)
    isMonster = 2;
  return getMonsterStateById(isMonster);
}

const std::string &Monster::getMonsterStateById(int id) const {
  return monsterStates[id];
}
