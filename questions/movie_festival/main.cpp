#include <bits/stdc++.h>
#define int int64_t
using namespace std;

signed main() {
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (auto &i : a) { cin >> i.first >> i.second; }
	sort(a.begin(), a.end(), [](auto first, auto second) -> bool {
		return first.first > second.first;
	});
	int counter = 0;
	int actual_begin = INT64_MAX;
	for (int i = 0; i < n; i++) {
		if (a[i].second <= actual_begin) {
			actual_begin = a[i].first;
			counter++;
		}
	}
	cout << counter << endl;
	return 0;
}
