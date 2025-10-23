#pragma once

#include "Credit.hpp"

class Factoring final : public Credit {
public:
  Factoring() : Credit("", 0) {}
  Factoring(const std::string &clientName, int creditSum)
      : Credit(clientName, creditSum) {}
  ~Factoring() = default;

  bool getCreditIssue() override { return true; }

  std::string getCreditName() const override { return "Factoring"; }
};
