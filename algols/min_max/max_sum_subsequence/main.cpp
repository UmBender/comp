#include <iostream>
#include <vector>


int zero_one(std::vector<int> seq) {
	int sum = 0;
	int max_sum = 0;
	for(auto i: seq) {
		sum += i;
	}
	max_sum = sum;

	for(int i = 0; i < (int) seq.size(); i++) {
		int actual_sum = sum;
		for(int j = i; j < (int) seq.size(); j++) {
			if(seq[j] == 0) {
				actual_sum+=1;
			}else{
				actual_sum-=1;
			}
			if(actual_sum > max_sum) {
				max_sum = actual_sum;
			}

		}
	}
	return max_sum;
}



int main(int argc, char **argv) {
	int n;
	std::cin >> n;
	std::vector<int> seq(n);
	for(int i = 0; i < n; i++) {
		std::cin >> seq[i];
	}
	std::cout << zero_one(seq) << std::endl;
  return 0;
}
