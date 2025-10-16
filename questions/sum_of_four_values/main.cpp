#include <bits/stdc++.h>
using namespace std;
#define int int64_t

void solution();
signed main() { solution(); }
void solution() {
	int n, x;
	cin >> n >> x;
	int a[n];
	for (int i = 0; i < n; i++) { cin >> a[i]; }
	unordered_map<int, pair<int, int>> hm;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int actual = a[i] + a[j];
			if (hm.count(x - actual)) {
				cout << i + 1 << " " << j + 1 << " " << hm[x-actual].first + 1
				     << " " << hm[x-actual].second + 1 << endl;
				return;
			}
		}
		for (int j = 0; j != i; j++) { hm[a[i] + a[j]] = {i, j}; }
	}
	cout << "IMPOSSIBLE" << endl;
}
