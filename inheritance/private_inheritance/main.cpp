#include <iostream> // библиотека данных для потокавывода сout
class Animal {      // объявляет класс Animal с публичным методом eat()
public:
  void eat() { std::cout << "Animal "; } // выводит "Animal "
};

void animal() { std::cout << "Global animal "; } // Объявляет глобальную функцию
// animal(), выводящую "Global animal ".

class Cat : private Animal { // бъявляет класс Cat, который приватно наследует
  // от Animal
public:
  void eat() { // Публичный метод eat() в классе Cat
    auto animalThis = static_cast<Animal *>(this); // риводит указатель this
    // (типа Cat*) к типу Animal* через static_cast
    animalThis->eat(); // Вызывает метод eat() базового класса Animal
    ::animal();        // Вызывает глобальную функцию animal()
    std::cout << "cat is eating.\n"; // выводит cat is eating
  }
};

int main(int argc, char *argv[]) { // Точка входа в программу
  // Animal *cat = new Cat(); -- нельзя так делать при приватном наследовании
  Cat *cat = new Cat(); // Создаёт объект Cat в динамической памяти и сохраняет
  // указатель на него
  cat->eat(); //  Вызывает метод eat()
  delete cat; // свобождает память, занятую объектом Cat
  return 0;
}
