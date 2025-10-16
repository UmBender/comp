#include <algorithm>
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
	vector<int> pref(n + 1);
	for (int i = 0; i < n; i++) { pref[i + 1] = pref[i] + a[i]; }
	map<int, vector<int>> posi;
	for (int i = 0; i <= n; i++) { posi[pref[i]].push_back(i); }
	int counter = 0;
	for (int i = 0; i < n; i++) {
		int target = x + pref[i];
		if (!posi.count(target)) { continue; }
		auto it = lower_bound(posi[target].begin(), posi[target].end(), i + 1);
		int num = (posi[target].end() - it);

		counter += num;
	}
	cout << counter << endl;
}
