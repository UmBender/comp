#include "dsu.hpp"
#include <iostream>

int main(int argc, char **argv) {
  int64_t size = 10;
  DSU dsu(size);
  for (int i = 1; i < 5; ++i)
    dsu.join(i, i + 1);
  for (int i = 6; i < 10; ++i)
    dsu.join(i, i + 1);

  std::cout << (dsu.same(1, 6) ? "Same set" : "Not same set") << std::endl;
  for (int64_t i{1}; i <= 10; ++i) {
    for (int64_t j{1}; j <= 10; ++j) {
      if (i == j)
        continue;
      std::cout << "Set: " << i << ", " << j << " "
           << (dsu.same(i, j) ? "Same set" : "Not same set") << std::endl;
    }
  }

  for(int64_t i{1}; i <= 10; ++i) {
    std::cout << "Size " << i << ": " << dsu.get_size(i) << std::endl;
  }
  return 0;
}
