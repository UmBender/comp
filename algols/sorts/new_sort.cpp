#include "new_sort.hpp"

void selection_sort(std::vector<int> &ref)
{
	for(int i = 0; i < (int) ref.size(); i++) {
		int pos = i;
		for(int j = pos + 1; j < (int) ref.size(); j++) {
			if(ref[pos] > ref[j]) {
				pos = j;
			}

		}
		if(pos != i) {
			int temp = ref[pos];
			ref[pos] = ref[i];
			ref[i] = ref[pos];
		}
	}
}
