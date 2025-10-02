#include "list.h"

template <typename T>
List<T>::List() : templateInstance(nullptr), prev(nullptr), next(nullptr) {}

template <typename T>
List<T>::List(T *val) : templateInstance(val), prev(nullptr), next(nullptr) {}

template <typename T>
List<T>::List(const List &templateInstance)
    : templateInstance(nullptr), prev(nullptr), next(nullptr) {}
