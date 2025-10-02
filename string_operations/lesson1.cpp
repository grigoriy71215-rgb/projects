#include <iostream>
#include <string>

/* Задача: найти в строке число вхождений другой подстроки, введенной
 * пользователем */

/* План:
 * 1. Создать указатель строки ourStringIterator
 * 2. Создать указатель строки subStringIterator
 * 3. Организовать цикл по строке, в котором: (while, for)
 * 3.1. Сравнить буквы по итераторам (if, ourStringIterator, subStringIterator)
 * 3.1.1. Если истина
 * 3.1.1.1. Вызываем функцию проверки совпадения
 * подстроки и строки с текущей позиции ourStringIterator
 * 3.1.2. Если ложь
 * 3.1.2.1. Переходим к следующему витку цикла (inc ourStringIterator)
 * 3.2. Функция проверки совпадения (возвр. совпало или нет)
 * 3.2.1. Параметры функции:
 * 3.2.1.1. ourStringIterator
 * 3.2.2. Сама процедура:
 * 3.2.2.0. Создать переменную совпадения bool isEqual = false
 * 3.2.2.1. Создать итератор на подстроку subStringIteratorForCheck
 * 3.2.2.2. Создаем цикл по подстроке, в котором:
 * 3.2.2.2.1. Переходим к следующим элементам по итераторам
 * 3.2.2.2.2. Сравнить буквы по итераторам oSI, sSIFC
 * 3.2.2.2.3. Если истина:
 * 3.2.2.2.3.1. isEqual = true - то есть говорим, что текущие элементы совпали
 * 3.2.2.2.4. Если ложь:
 * 3.2.2.2.4.1. Возвращает, что не совпало
 * 3.2.2.3. Возвратить isEqual*/

std::string ourString = "Test example string";
std::string subString = "st";

bool compareSignsByIterators(std::string::const_iterator ourStringIterator,
                             std::string::const_iterator subStringIterator) {
  return *ourStringIterator == *subStringIterator;
}

int checkSubstringByOurStringIterator(std::string::iterator ourStringIterator) {
  int isEqual = 0;
  std::string::iterator subStringIteratorForCheck = subString.begin();
  while (subStringIteratorForCheck <= subString.end()) {
    ++ourStringIterator;
    ++subStringIteratorForCheck;
    if (*ourStringIterator == *subStringIteratorForCheck) {
      isEqual = 1;
    } else if (*subStringIteratorForCheck != '\0') {
      return 0;
    }
  }
  return isEqual;
}

size_t getCountOfInclussionsSubInOur() {
  std::string::iterator ourStringIterator = ourString.begin();
  std::string::iterator subStringIterator = subString.begin();
  size_t count = 0;
  while (ourStringIterator <= ourString.end()) {
    if (compareSignsByIterators(ourStringIterator, subStringIterator)) {
      count += checkSubstringByOurStringIterator(ourStringIterator);
    }
    ++ourStringIterator;
  }
  return count;
}

void getResult(int result) { std::cout << result << '\n'; }

int main(int argc, char *argv[]) {
  size_t count = getCountOfInclussionsSubInOur();
  getResult(count);
  return 0;
}
