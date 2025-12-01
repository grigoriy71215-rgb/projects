#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main(int argc, char *argv[]) {
  int i = 5;
  int j = 6;
  int *pi = &i;
  int *pj = &j;
  std::cout << *pi << ' ' << *pj << '\n';
  pi = pj;
  *pi = 6;
  std::cout << i << ' ' << j << '\n';

  int array[] = {7, 2, 3};
  std::cout << *(array + 2) << '\n';

  std::vector<int> s = {2, 3, 4, 5};
  std::cout << std::count(s.begin(), s.end(), 's') << '\n';
  std::cout << std::accumulate(s.begin(), s.end(), 5) << '\n';
  return 0;
}
