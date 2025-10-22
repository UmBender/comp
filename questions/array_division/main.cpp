#include <bits/stdc++.h>
using namespace std;
#define int int64_t
void solution();
signed main() { solution(); }
void solution() {
	int n, k;
	cin >> n >> k;
	vector<int> x(n);
	for (auto &i : x) { cin >> i; }
	int left = 1, right = 1e18;
	int minimal = 1e18;
	auto is_possible = [&](int max_value) {
		int acc = 0;
		int parts = 1;
		for (int i = 0; i < n; i++) {
			if (x[i] > max_value) { return false; }
			if (acc + x[i] > max_value) {
				acc = 0;
				acc = x[i];
				parts++;

			} else {
				acc += x[i];
			}
		}
		return (parts <= k);
	};
	while (left <= right) {
		int middle = left + (right - left) / 2;
		if (is_possible(middle)) {
			minimal = middle;
			right = middle - 1;
		} else {
			left = middle + 1;
		}
	}
	cout << minimal << endl;
}
