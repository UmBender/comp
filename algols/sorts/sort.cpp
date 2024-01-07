#include "sort.hpp"
void bubble_sort(std::vector<int> &ref)
{
	for(int i = 0; i < (int) ref.size(); i++) {
		for(int j = 0; j < (int) ref.size() -1; j ++) {
			if(ref[j] > ref[j + 1]){
				int temp = ref[j];
				ref[j] = ref[j + 1];
				ref[j + 1] = temp;
			}
		}
	}
}


void selection_sort(std::vector<int> &ref)
{
	for(int i = 0; i < (int) ref.size(); i++) {
		int swap = i;
		for(int j = i; j < (int) ref.size(); j++) {
			if(ref[swap] > ref[j]) {
				swap = j;
			}

		}
		if(swap != i) {
			int temp = ref[swap];
			ref[swap] = ref[i];
			ref[i] = temp;
		}
	}
}



