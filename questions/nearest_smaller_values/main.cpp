#include <bits/stdc++.h>
using namespace std;
#define int int64_t
void solution();
signed main() { solution(); }
void solution() {
	int n;
	cin >> n;
	int x[n];
	for (int i = 0; i < n; i++) { cin >> x[i]; }
	vector<pair<int, int>> posi;
	auto find = [&](int value) -> int {
		int left = 0, right = posi.size() - 1;
		int pos = -1;
		while (left <= right) {
			int middle = (left + right) / 2;
			if (posi[middle].first < value) {
				pos = middle;
				left = middle + 1;
			} else {
				right = middle - 1;
			}
		}
		return pos;
	};
	auto removes = [&](int size) -> void {
		while (posi.size() > size) { posi.pop_back(); }
	};

	vector<int> results;
	for (int i = 0; i < n; i++) {
		int lower = find(x[i]);
		if (lower == -1) {
			results.push_back(0);
			removes(0);
			posi.push_back({x[i], i});
		} else {
			results.push_back(posi[lower].second + 1);
			removes(lower + 1);
			posi.push_back({x[i], i});
		}
	}
	for (int i = 0; i < n; i++) { cout << results[i] << " "; }
	cout << endl;
}
