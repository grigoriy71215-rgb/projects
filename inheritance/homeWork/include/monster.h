#pragma once

#include <chrono> // библиотека данных для потока вывода chrono
#include <string> // библиотека данных для потока вывода string
#include <vector> // библиотека данных для потока вывода vector

class Monster { // создаем класс monster

  int isMonster; // объявляет переменную isMonster
  std::chrono::system_clock::time_point biteDate; // обьявляет переменную
  // biteDate c типом system_clock
  std::vector<std::string> monsterStates = {"human", "monstering", "monster"};
  // объявляет и инициализирует вектор строк monsterStates

  std::chrono::duration<double>
  getBiteDuration() const; // объявляет функцию getBiteDuration
  const std::string &
  getMonsterStateById(int id) const; // объявляет функцию getMonsterStateById

protected:
  Monster() {} // конструктор по умолчанию

public:
  void biting(); // функция biting без возвращающиго типа void
  const std::string &getIsMonster(); // возврощает константную сылку на строку
};
