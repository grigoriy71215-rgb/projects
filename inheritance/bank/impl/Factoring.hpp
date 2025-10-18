#pragma once

#include "../abstracts/Credit.hpp"

class Factoring final : public Credit {
public:
  Factoring() : Credit("", 0) {}
  Factoring(const std::string &clientName, int creditSum)
      : Credit(clientName, creditSum) {}
  ~Factoring() = default;

  bool getCreditIssue() { return true; }
};
