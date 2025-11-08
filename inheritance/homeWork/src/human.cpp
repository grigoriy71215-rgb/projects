#include "human.h" // библиотека данных для потока вывода соut

Human::Human() : Monster() {}    // конструктор
void Human::bite() { biting(); } // определение метода bite
const std::string &
Human::getIsMonster() { // метод getIsMonster, который возвращает
  // константную ссылку на std::string
  return static_cast<Monster *>(this)->getIsMonster(); // тело метода
}
