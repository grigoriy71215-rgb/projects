#include <iostream> // библиотека данных для потока вывода сout
class Animalize {   // Начинает объявление абстрактного класса Animalize
protected:
  Animalize() = default; // создать экземпляр этого класса напрямую нельзя, но
  // наследники могут его использовать
public:
  virtual ~Animalize() =
      default; // Объявление виртуального деструктора по умолчанию
  virtual void
  animalize() = 0; // Объявление чисто виртуальной функции animalize };
};

class Flyable { // Начинает объявление абстрактного класса Flyable
protected:
  Flyable() = default; // Защищенный конструктор по умолчанию, аналогично классу
                       // Animalize

public:
  virtual ~Flyable() = default; // Виртуальный деструктор по умолчанию
  virtual void flyable() = 0;   // Чисто виртуальная функция flyable(), делающая
  // класс абстрактным
};

class Bird : public Animalize, public Flyable { // Объявление класса Bird,
  // который публично наследуется от обоих абстрактных классов (Animalize и
  // Flyable
public:
  void animalize() override { std::cout << "Bird is animal\n"; } // Реализация
  // чисто виртуальной функции animalize() из класса Animalize

  void flyable() override { std::cout << "Bird is flying\n"; } // Реализация
  // чисто виртуальной функции flyable() из класса Flyable
};

int main(int argc, char *argv[]) {
  Bird *bird = new Bird();
  bird->animalize();
  bird->flyable();
  delete bird;
  Animalize *animal = dynamic_cast<Animalize *>(bird);
  animal->animalize();
  // animal->flyable(); // error!
  Flyable *flyable = dynamic_cast<Flyable *>(bird);
  flyable->flyable();
  // flyable->animalize(); // error!
  return 0;
}
