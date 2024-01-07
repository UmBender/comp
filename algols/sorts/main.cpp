#include <iostream>
#include <vector>
#include <list>
#include "sort.hpp"

int main(int argc, char** argv)
{
	std::vector<int> valores = {3,7,1,2,9,4,6,0};
	selection_sort(valores);
	for(auto i: valores) {
		std::cout << i << std::endl;
	}
	return 0;
}
