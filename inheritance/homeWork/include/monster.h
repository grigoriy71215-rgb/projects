#pragma once

#include <chrono>
#include <string>
#include <vector>

class Monster {

  int isMonster;
  std::chrono::system_clock::time_point biteDate;
  std::vector<std::string> monsterStates = {"human", "monstering", "monster"};

  std::chrono::duration<double> getBiteDuration() const;
  const std::string &getMonsterStateById(int id) const;

protected:
  Monster() {}

public:
  void biting();
  const std::string &getIsMonster();
};
