#include <iostream>
#include <ranges>
#include <vector>

std::vector<int> vint{1, 2, 3, 4, 5, 6};

int main() {
  const auto is_even = [](const int &i) { return i % 2 == 0; };
  const auto even = vint | std::views::filter(is_even);
  for (auto &i : even) {
    ++i;
  }
  for (auto i : vint) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
  return 0;
}
