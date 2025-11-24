#include <iostream>
#include <numeric>
#include <vector>

class Butterfly final {
  int spots;

public:
  Butterfly() = default;
  Butterfly(int spots) { this->spots = spots; }
  Butterfly(const Butterfly &other) { spots = other.spots; }
  Butterfly &operator=(const Butterfly &other) {
    spots = other.spots;
    return *this;
  }
  ~Butterfly() = default;

  Butterfly &operator+(Butterfly other) {
    spots += other.spots;
    return *this;
  }

  int getSpots() const noexcept { return spots; }
};

// порядок выполнения не гарантируется
int reduceSpotsCount(std::vector<Butterfly> &butterflies) {
  return std::reduce(butterflies.begin(), butterflies.end(), 0,
                     [](const Butterfly &one, const Butterfly &two) {
                       return one.getSpots() + two.getSpots();
                     });
}

// строгое выполнение слева направо
int accumulateSpotsCount(std::vector<Butterfly> &butterflies) {
  return std::accumulate(butterflies.cbegin(), butterflies.cend(), 0,
                         [](const Butterfly &one, const Butterfly &two) {
                           return one.getSpots() + two.getSpots();
                         });
}
int main(int argc, char *argv[]) {
  std::vector<Butterfly> butterflies = {
      Butterfly(4), Butterfly(5), Butterfly(3), Butterfly(7), Butterfly(10)};
  int result = accumulateSpotsCount(butterflies);
  std::cout << "Spots count is " << result << '\n';
  return 0;
}
