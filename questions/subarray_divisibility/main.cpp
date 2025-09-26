#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int a[200100];
int n;

signed main() {
	cin >> n;
	for (int i = 0; i < n; i++) { cin >> a[i]; }
	int pref[n + 1];
	pref[0] = 0;
	vector<vector<int>> pos(n);
	for (int i = 0; i < n; i++) {
		pref[i + 1] = (pref[i] + a[i]) % n;
		if (pref[i + 1] < 0) { pref[i + 1] += n; }
	}
	for (int i = 0; i <= n; i++) { pos[pref[i]].push_back(i); }
	int counter = 0;
	for (int i = 0; i < n; i++) {
		int num = pos[i].size();
		counter += ((num - 1) * num) / 2;
	}
	cout << counter << endl;
}
