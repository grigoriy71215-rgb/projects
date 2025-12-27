#pragma once

#include <iostream>
#include <string>
#include <memory>

class SafeInput final {
private:
  class Impl;
  std::unique_ptr<Impl> pImpl;

public:
  SafeInput();
  explicit SafeInput(const std::string& customPrompt);
  ~SafeInput();

  SafeInput(const SafeInput&) = delete;
  SafeInput& operator=(const SafeInput&) = delete;

  SafeInput(SafeInput&&) noexcept;
  SafeInput& operator=(SafeInput&&) noexcept;

  template<typename T>
  T get();

  std::string getString();
  void setPrompt(const std::string& newPrompt);
};
