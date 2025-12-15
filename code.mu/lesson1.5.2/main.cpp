#include <future>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

int value = -100;
std::mutex mtx;

bool isMultipliesOfSeven() { return value % 7 == 0; }

void printMultipliesOfSeven(int thread_id) {
  std::lock_guard<std::mutex> lock(mtx);
  if (isMultipliesOfSeven() && value < 100)
    std::cout << "Thread: " << thread_id << ". Value: " << value << '\n';
  ++value;
}

int main() {
  int thread_id = 0;
  std::vector<std::thread> threads;
  while (value < 100) {
    std::thread t([thread_id] { printMultipliesOfSeven(thread_id); });
    threads.push_back(std::move(t));
    ++thread_id;
  }
  for (auto &thread : threads) {
    thread.join();
  }
  return 0;
}

int futures() {
  int task_id = 0;
  while (value < 100) {
    auto future = std::async(printMultipliesOfSeven, task_id);
    future.get();
    ++task_id;
  }
  return 0;
}
