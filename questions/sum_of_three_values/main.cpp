#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define int int32_t
void solution();
signed main() { solution(); }

void solution() {
	int n, x;
	cin >> n >> x;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	vector<int> aa(n);
	for (int i = 0; i < n; i++) { aa[i] = a[i].first; }

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int target = x - aa[i] - aa[j];
			if (target < aa[j]) { break; }
			auto it = lower_bound(aa.begin() + j + 1, aa.end(), target);
			if (it == aa.end()) { continue; }
			if (*it != target) { continue; }
			cout << a[i].second + 1 << " " << a[j].second + 1 << " "
			     << a[it - aa.begin()].second + 1 << endl;
			return;
		}
	}

	cout << "IMPOSSIBLE" << endl;
}
