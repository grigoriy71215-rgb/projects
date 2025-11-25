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

using cir = const int &;

int sumOfRanks(int i) {
  std::vector<int> ranks;
  while (i != 0) {
    ranks.push_back(i % 10);
    i /= 10;
  }
  return std::accumulate(ranks.begin(), ranks.end(), 0, std::plus<>());
}

std::mutex cout_mutex;

void fillLambdas(std::vector<void (*)(cir)> &lambdas) {
  lambdas.push_back([](cir i) {
    std::lock_guard<std::mutex> lock(cout_mutex);
    if (i % 2 == 0) {
      std::cout << i << " is even\n";
    }
  });
  lambdas.push_back([](cir i) {
    std::lock_guard<std::mutex> lock(cout_mutex);
    std::cout << "Sum of ranks is " << sumOfRanks(i) << '\n';
  });
  lambdas.push_back([](cir i) {
    std::lock_guard<std::mutex> lock(cout_mutex);
    if (i > 10) {
      std::cout << i << " is greater than ten\n";
    }
  });
}

void processLambdas(const std::vector<void (*)(cir)> lambdas, const int &i) {
  std::vector<std::future<void>> futures;
  for (auto func : lambdas) {
    futures.push_back(std::async(std::launch::async, [func, i]() { func(i); }));
  }
  for (auto &future : futures) {
    future.wait();
  }
}

void processLambdasOriginal(const std::vector<void (*)(cir)> lambdas,
                            const int &i) {
  std::for_each(std::execution::par, lambdas.begin(), lambdas.end(),
                [i](auto func) { func(i); });
  std::this_thread::sleep_for(std::chrono::milliseconds(1500));
}

int main(int argc, char *argv[]) {
  int i = 54;
  std::vector<void (*)(cir i)> lambdas;
  fillLambdas(lambdas);
  processLambdas(lambdas, i);
  std::cout << "All lambdas completed!\n";
  return 0;
}
