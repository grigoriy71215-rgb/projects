#include <iostream> // библиотека данных для потока вывода cout

class Animal { // animal - животное
public:        // публичные члены класса
  virtual void eat() = 0;
  virtual void jump() = 0;

  virtual ~Animal() = default; // определяем этот метод автомотически
};

class Lion final : public Animal { // пишем класс Lion, наследуемый от Animal
public:                            // публичные члены класса
  void eat() override {            // override - перегрузить метод родителя
    std::cout << "Lion is eating\n";
  } // выводим на экран Lion is eating
  void jump() override {
    std::cout << "Lion is jumping\n";
  } // выводим на экран Lion is jumping
  ~Lion() = default; // определяем этот метод автомотически
};

/* Задача: написать класс Собака, наследуемый от Animal */

class Dog final : public Animal { // записываем класс Dog, наследуемый от Animal
public:                           // публичные члены класса
  void eat() override {
    std::cout << "Dog is eating\n";
  } // выводим на экран Dog is eating
  void jump() override {
    std::cout << "Dog is jumping\n";
  } // выводим на экран Dog is jumping
  ~Dog() = default; // определяем этод метод автомотически
};

int main(int argc, char *argv[]) { // функция с каторой начинается программа
  Animal *lion = new Lion();
  lion->eat();
  delete lion;
  return 0; // возвращаем 0
}

/*Традиционным способом придать переменной b значение переменной a является
 * копирование. Для целого значения в памяти это может выполнить посредством
 * единтвенным что имеет смысл; это как раз то, что аппаратура может выполнить
 * посредством единтвенной инструкции. А вот с общей логической точки зрения
 * дело обстоит иначе.*/
