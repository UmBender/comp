#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

int32_t main() {
	int n;
	cin >> n;
	int a[n], b[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; i++) {
		if (a[i] > a[i + 1]) {
			cout << -1 << endl;
			return 0;
		}
	}
	for (int i = 0; i < n; i++) {
		if (!(a[i] <= i + 1)) {
			cout << -1 << endl;
			return 0;
		}
	}
	set<int> bUsable;
	for (int i = 0; i < 2 * n; i++) {
		bUsable.insert(i);
	}
	map<int, int> lastTime;
	for (int i = 0; i < n; i++) {
		lastTime[a[i]] = max(lastTime[a[i]], i);
		if (bUsable.count(a[i])) {
			bUsable.erase(a[i]);
		}
	}
	for (int i = 0; i < n; i++) {
		int minimal = *bUsable.begin();
		bUsable.erase(minimal);
		b[i] = minimal;
		if (i == lastTime[a[i]]) {
			//cout << "adicionou: " << a[i] << " i: " << i << endl;
			bUsable.insert(a[i]);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << b[i] << " \n"[i == n - 1];
	}
	
	return 0;
}
