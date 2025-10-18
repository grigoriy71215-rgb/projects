#pragma once

#include "../abstracts/Credit.hpp"

class ConsumerCredit final : public Credit {
public:
  ConsumerCredit() : Credit("", 0) {}
  ConsumerCredit(const std::string &clientName, int creditSum)
      : Credit(clientName, creditSum) {}
  ~ConsumerCredit() = default;

  bool getCreditIssue() {
    if (creditSum < 10000)
      return false;
    return true;
  }
};
