#include <algorithm>
#include <chrono>
#include <execution>
#include <functional>
#include <future>
#include <iostream>
#include <mutex>
#include <numeric>
#include <thread>
#include <vector>

using cir = const int
    &; //  создает псевдоним cir для const int & (константная ссылка на int)

int sumOfRanks(int i) {   // вычисляет сумму цифр числа
  std::vector<int> ranks; // для хранения цифр числа
  while (i != 0) {        // разбирает число на цифры
    ranks.push_back(i % 10);
    i /= 10;
  }
  return std::accumulate(
      ranks.begin(), ranks.end(), 0,
      std::plus<>()); // сумма всех цифр с использованием std::accumulate
}

std::mutex cout_mutex; // для синхронизации вывода в cout из разных потоков

void fillLambdas(
    std::vector<void (*)(cir)> &lambdas) { // заполняет вектор лямбда-функциями
  lambdas.push_back([](cir i) {
    std::lock_guard<std::mutex> lock(cout_mutex);
    if (i % 2 == 0) {
      std::cout << i
                << " is even\n"; // проверяет четность числа (с синхронизацией)
    }
  });
  lambdas.push_back([](cir i) { // выводит сумму цифр числа
    std::lock_guard<std::mutex> lock(cout_mutex);
    std::cout << "Sum of ranks is " << sumOfRanks(i) << '\n';
  });
  lambdas.push_back([](cir i) { // проверяет, больше ли число 10
    std::lock_guard<std::mutex> lock(cout_mutex);
    if (i > 10) {
      std::cout << i << " is greater than ten\n";
    }
  });
}

void processLambdas(const std::vector<void (*)(cir)> lambdas,
                    const int &i) {       // выполняет лямбды асинхронно
  std::vector<std::future<void>> futures; // для отслеживания асинхронных задач
  for (auto func : lambdas) {
    futures.push_back(std::async(std::launch::async, [func, i]() {
      func(i);
    })); //  запускает каждую лямбду асинхронно через std::async
  }
  for (auto &future : futures) {
    future.wait(); // ждем окончания всех лямбд
  }
}

void processLambdasOriginal(
    const std::vector<void (*)(cir)> lambdas,
    const int &i) { // для параллельного выполнения (не используется)
  std::for_each(std::execution::par, lambdas.begin(), lambdas.end(),
                [i](auto func) { func(i); }); // выполняет лямбды параллельно
  std::this_thread::sleep_for(
      std::chrono::milliseconds(1500)); // приостанавливает выполнение
}

int main(int argc, char *argv[]) { // точка входа в программу
  int i = 54;                      // число
  std::vector<void (*)(cir i)>
      lambdas;                // указателей на функции, принимающие const int&
  fillLambdas(lambdas);       // заполняет вектор функциями
  processLambdas(lambdas, i); // // выполняет лямбды асинхронно
  std::cout << "All lambdas completed!\n"; // выводит завершающую строку
  return 0;
}
