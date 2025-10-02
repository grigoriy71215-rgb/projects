#pragma once                    // директива препроцессора, говорящая о том, чтобы заголовочный файл не включался несколько раз в один и тот же контекст

#include <cstdlib>

class vector {

private:                // закрытые члены класса
  int *array = nullptr; // массив
  int *ptr = nullptr;   // указатель для получения конкретного элемента массива
  unsigned char size = 5;     // размер массива
  unsigned char capacity = 0; // сколько элементов записано в массив

public:      // публичные (общедоступные) члены класса
  using iterator = int *; // iterator присваеваем к int *
  vector();                       // конструктор по умолчанию
  ~vector();                      // деструктор

  iterator back() noexcept;           // получение последнего элемента
  iterator front() noexcept;          // получение первого элемента

  unsigned char getSize() const noexcept; // получение размера массива
  unsigned char getCapacity() const noexcept; // получение capacity noexcept

  void push_back(int value);              // добавление элемента в конец массива
  void remove(iterator it);               // удаление по указателю

  iterator at(int elementOrder) noexcept; // получение итератора по порядковому номеру элемента
  const iterator at(int elementOrder) const noexcept; // константный at

  void sortDescent() noexcept;
  void sortAscend() noexcept;
  void sort(bool (*predicate)(const iterator &first, const iterator &second)); // predicate - это ссылка на функцию-предикат, у которой 2 целочисленных аргумента

private:
  bool isGreater(const iterator &first, const iterator &second) const;               // 
  bool isLess(const iterator &first, const iterator &second) const;

  void sort(bool (vector::*predicate)(const iterator &first, const iterator &second) const); // predicate - это ссылка на функцию-предикат, у которой 2 целочисленных аргумента
};
