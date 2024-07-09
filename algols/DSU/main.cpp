#include "dsu.hpp"
#include <iostream>

int main(int argc, char **argv) {
  Vec<int> valores(100);
  for (int i = 0; i < 100; i++) {
		valores[i] = i;
  }

	for(int i = 0; i < valores.size(); i++) {
		std::cout << valores[i] << std::endl;
	}

  return 0;
}
