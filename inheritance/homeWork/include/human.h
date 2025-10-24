#pragma once

#include "monster.h"

class Human final : public Monster {
  bool isBiting = false;

public:
  Human();
  void bite();
  const std::string &getIsMonster();
};
