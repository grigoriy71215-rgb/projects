#include "monster.h" // библиотека данных для потока вывода std::monster

std::chrono::duration<double> Monster::getBiteDuration() const { // Определение
  // метода getBiteDuration, который возвращает продолжительность
  // типа std::chrono::duration<double>.
  return std::chrono::system_clock::now() - biteDate; // Возвращает разницу
  // между текущим временем и временем последнего укуса (biteDate).
}

void Monster::biting() { biteDate = std::chrono::system_clock::now(); } //
// Устанавливает biteDate в текущее время

const std::string &Monster::getIsMonster() { // Определение метода getIsMonster,
  // возвращающего константную ссылку на строку.
  auto duration = getBiteDuration().count(); // Объявление переменной duration,
  // которая получает количество секунд (в double) с последнего укуса
  if (duration < 5 || duration >= 10000) // Если с момента укуса прошло меньше
    // 5 секунд ИЛИ больше или равно 10000 секунд, устанавливает isMonster = 0
    isMonster = 0;
  else if (duration < 10) // Иначе, если прошло меньше 10 секунд, устанавливает
    // isMonster = 1.
    isMonster = 1;
  else if (duration >= 10 && duration < 10000) // Иначе, если прошло от 10 до
    // 10000 секунд, устанавливает isMonster = 2.
    isMonster = 2;
  return getMonsterStateById(isMonster); // Возвращает строку, соответствующую
  // состоянию монстра по ID isMonster.
}

const std::string &Monster::getMonsterStateById(int id) const { // Определение
  // метода getMonsterStateById, который возвращает константную ссылку на строку
  // по переданному ID
  return monsterStates[id];
}
