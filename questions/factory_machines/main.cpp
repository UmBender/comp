#include <bits/stdc++.h>
using namespace std;
#define int __int128
void solution();

signed main() { solution(); }

void solution() {
	int64_t n, t;
	cin >> n >> t;
	int k[n];
	for (int i = 0; i < n; i++) {
		int64_t holder;
		cin >> holder;
		k[i] = holder;
	}
	int minimal = -1;
	int left = 1;
	int right = 1e27 + 100;
	auto sum = [&](int time) -> int {
		int products = 0;
		for (int i = 0; i < n; i++) { products += time / k[i]; }
		return products;
	};

	while (left <= right) {
		int middle = left + (right - left) / 2;
		int actual_sum = sum(middle);
		if (actual_sum >= t) {
			minimal = middle;
			right = middle - 1;

		} else {
			left = middle + 1;
		}
	}
	assert(minimal != -1);
	cout << (int64_t)minimal << endl;
}
