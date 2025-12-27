#include "system/SafeInput.h"

#include <iostream>
#include <sstream>
#include <utility>

class SafeInput::Impl {
private:
  std::string prompt;

public:
  Impl(std::string customPrompt) : prompt(std::move(customPrompt)) {}

  template <typename T> T get() {
    T value;
    std::string input;
    while (true) {
      std::cout << prompt;
      std::getline(std::cin, input);
      std::istringstream iss(input);
      if (iss >> value && iss.eof()) {
        return value;
      }
      std::cout << "Ошибка! Неверный формат данных. Попробуйте снова.\n";
    }
  }

  std::string getString() {
    std::string value;
    while (true) {
      std::cout << prompt;
      if (std::getline(std::cin, value) && !value.empty()) {
        return value;
      }
      std::cout << "Ошибка! Введите непустую строку.\n";
    }
  }

  void setPrompt(const std::string &newPrompt) { prompt = newPrompt; }
};

SafeInput::SafeInput() : pImpl(std::make_unique<Impl>("Введите значение: ")) {}
SafeInput::SafeInput(const std::string &customPrompt)
    : pImpl(std::make_unique<Impl>(customPrompt)) {}
SafeInput::~SafeInput() = default;

SafeInput::SafeInput(SafeInput &&) noexcept = default;
SafeInput &SafeInput::operator=(SafeInput &&) noexcept = default;

std::string SafeInput::getString() { return pImpl->getString(); }

void SafeInput::setPrompt(const std::string &newPrompt) {
  pImpl->setPrompt(newPrompt);
}

template <typename T> T SafeInput::get() { return pImpl->get<T>(); }

template int SafeInput::get<int>();
template double SafeInput::get<double>();
template float SafeInput::get<float>();
template char SafeInput::get<char>();
template bool SafeInput::get<bool>();
template long SafeInput::get<long>();
template long long SafeInput::get<long long>();
