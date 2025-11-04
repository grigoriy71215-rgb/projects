#pragma once

#include "monster.h" // библиотека данных для потока вывода monster

class Human final : public Monster {
  bool isBiting = false; // объявление приватного поля isBiting типа bool

public:        // публичные члены класса
  Human();     // конструктор по умалчанию
  void bite(); // метод bite, который не принимает аргументов
  const std::string &getIsMonster(); // метод getIsMonster, который возвращает
  // константную ссылку
};
