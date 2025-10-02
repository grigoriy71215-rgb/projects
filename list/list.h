
/* Задание: написать:
 * - конструктор по умолчанию,
 * - конструктор, принимающий в качестве параметра T *templateInstance,
 * - конструктор, принимающий в качестве параметров T *templateInstance, List
 * *prev, List *next,
 * - конструктор копирования
 * - конструктор перемещения
 * - оператор копирования
 * - оператор перемещения
 * - метод вставки в начало
 * - метод вставки в конец
 * - метод вставки в середину
 * - метод удаления по экземпляру
 *   метод удаления по экземпляру рекурсивный*/

#pragma once

template <typename T> class List {

private:
  T *templateInstance = nullptr;
  List *prev = nullptr; // previous
  List *next = nullptr; // next

public:
  List();  // конструктор по умолчанию
  ~List(); // деструктор

  List(T *val); // конструктор копирования
  List(const List &templateInstance); // конструктор, принимающий в качестве
                                      // параметра T *templateInstance
  List(List &&
           templateInstance); // конструктор, принимающий в качестве параметров
                              // T *templateInstance, List *prev, List *next,

  List &operator=(const List &templateInstance); // оператор копирования
  List &operator=(List &&templateInstance);      // оператор перемещения

  void incertAtBeginning(List prev);       // метод вставки в начало
  void incertAtEnd(List next);             // метод вставки в конец
  void incertInMiddle(T templateInstance); // метод вставки в середину

  void removeByInstance(T *val); // метод удаления по экземпляру
  void
  removeByInstanceRecursive(T *val); // метод удаления по экземпляру рекурсивный
};
