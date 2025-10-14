#pragma once
#include <functional>
#include <string>

class VowelGetter {
private: // скрытые члены класса
  void getVowelsDictionary();
  bool isVowel(char ch); // функция поиска совпадения строки и
  // подстроки возвращает номер символа в строке, с которого есть совподение
  int getPosByIterator(std::string::iterator stringIterato); // функция высокого
  // порядка (в параметрах есть указатель на функцию) для реализации способа
  // подсчета того, что находит функция по указателю
  // вызов функции iterate с параметром getInclusion
  int getVowelInclusion(VowelGetter *obj, int value, int pos);
  std::string ourString; // строка, в которой мы ищем число вхождений подстроки
  std::string subString; // подстрока
  int countOfOccurrences = 0;
  bool stringModified = true;

public:
  VowelGetter(); // конструктор по умолчанию
  VowelGetter(
      const std::string &ourString,
      const std::string &subString); // конструктор с пользовательскими
                                     // параметрами (задает строку и подстроку)
  ~VowelGetter() = default;          // деструктор

  int iterate(std::function<int(VowelGetter *, int, int)> stepFunc, int value,
              int pos); // функция высокого порядка (в параметрах есть указатель
                        // пользовательская логика вызова подсчета
  std::string::iterator getIteratorByPos(int pos);
  int process();
};
