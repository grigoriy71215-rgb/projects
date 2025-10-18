#pragma once

#include <string>

class Credit {
  Credit() = delete;

protected:
  std::string clientName;
  int creditSum;

public:
  virtual ~Credit() = default;
  Credit(const std::string &clientName, int creditSum)
      : clientName(clientName), creditSum(creditSum) {}
  virtual bool getCreditIssue() = 0;
};
