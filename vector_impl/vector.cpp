#include "vector.h"

vector::vector() {                           // конструктор
  array = (int *)malloc(size * sizeof(int)); // разметка памяти массива
  ptr = array;                               // указывает на 1-й элемент массива
}

vector::~vector() { // деструктор
  free(array);
}

vector::iterator vector::back() noexcept { // находим последний элемент массива ptr = array;                 // ставим указатель на первый элемент массива
  ptr = ptr + size - 1;        // прибавляем size - 1
  return ptr;                  // возврат указателя
}

vector::iterator vector::front() noexcept { // находим первый элемент массива
  ptr = array;                  // ставим указатель на первый элемент массива
  return ptr;                   // возврат указателя
}

unsigned char
vector::getSize() const noexcept { // находим максимальное значение массива
  return size;                     // возврат size
}

voaid vector::push_back(int value) { // функция value push_back(int value)
  if (capacity < size) {            // Проверяем capacity < size
    ptr = array + capacity; // Если меньше, то добавляем по смещению array+capacity
    *ptr = value;   // получения значения по адресу
  } else if (capacity == size) { //  Если равно
    int *newArray = (int *)malloc(2 * capacity * sizeof(int)); // разметка памяти массива
    for (int i = 0; i < capacity; ++i)                 //  Копируем из старого все элементы в новое
      newArray[i] = array[i]; // копируем i-тый элемент
    free(array);              // удаление памяти
    array = newArray;         // старый указатель переводим в новый
    array[capacity] = value;  // Добавляем новый элемент в конец массива
  }
  ++capacity;                 // наращивание количества элементов в массиве (сколько уже занесено)
}

void vector::remove(const vector::iterator it) { // функция удаление по указателю
  if (array < it && it <= array + capacity) { // array + capacity дает адрес последнего
                                // элемента, проверка на то, что итератор больше
                                // адреса первого элемента и меньше или равен
                                // адресу последнего элемента
    ptr = it; // ставим указатель ptr на место удаляемого элемента
    while (ptr < array + capacity) { // цикл перемещения оставшихся в конце массива элементов на место с адреса удяляемого элемента и дальше
      *ptr = *(ptr + 1); // ptr + 1 - это следующий за ptr элемент, здесь происходит присвоение значения следующего за ptr элемента по адресу ptr
      ++ptr;    // указатель переходит на следующий элемент
    }
    --capacity; // уменьшаем количество элементов в массиве на один
  }
}

vector::iterator vector::at(int elementOrder) noexcept {                                      // Функция int at(int elementOrder) noexcept
  if (capacity == 0)                                                                        // В массиве нет элементов 
    return nullptr;                                                                         // возвращаем nullptr
  if (capacity < elementOrder)                                                              // Capacity >= elementOrder
    return nullptr;                                                                         // возвращаем nullptr
  ptr = array + elementOrder;                                                               // Ставим указатель ptr на место запрашиваемого элемента (начиная с array)
  return ptr;                                                                               // возвращаем указатель
}

unsigned char vector::getCapacity() const noexcept {                                                // находим количество элементов в массиве  
  return capacity;                                                                                    // возврат capacity
}

const vector::iterator vector::at(int elementOrder) const noexcept {
  if (capacity == 0)                                                                        // В массиве нет элементов 
    return nullptr;                                                                         // возвращаем nullptr
  if (capacity < elementOrder)                                                              // Capacity >= elementOrder
    return nullptr;                                                                         // возвращаем nullptr
  return array + elementOrder;
}

bool vector::isGreater(const iterator &first, const iterator &second) const {               // правило перестоновки от большего к меньшему return *first > *second      
  return *first > *second;                                                                  // возврощаем *first > *second 
}

bool vector::isLess(const iterator &first, const iterator &second) const {                  // правило перестоновки от меньшего к большему return *first > *second
  return *first < *second;                                                                  // вoзвpoщaeм *first < *second
}

void vector::sort(bool (vector::*predicate)(const iterator &first, const iterator &second) const) { for (iterator first = array; first < array + capacity; ++first)    // predicate - это ссылка на функцию-предикат, у которой 2 целочисленных аргумента
    for (iterator second = array; second < array + capacity; ++second) {                    // 
      if ((this->*predicate)(first, second)) {
        int buffer = *first;
        *first = *second;
        *second = buffer;
      }
    }
}

void vector::sort(bool (*predicate)(const iterator &first, const iterator &second)) { for (iterator first = array; first < array + capacity; ++first)
    for (iterator second = array; second < array + capacity; ++second) {
      if (predicate(first, second)) {
        int buffer = *first;
        *first = *second;
        *second = buffer;
      }
    }
}

void vector::sortDescent() noexcept {
  sort(&vector::isGreater);
}

void vector::sortAscend() noexcept {
  sort(&vector::isLess);
}
