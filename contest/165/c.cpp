#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(n - 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; i++) {
		cin >> b[i];
	}

	ll mmin = 1e9;
	for (int i = 0; i < 2; i++) {
		int ops = 0;
		int actual = i;
		for (int j = 0; j < n; j++) {
			if (a[j] != actual) {
				ops ++;
			}
			if (j < n - 1) {
				actual = (b[j] - actual + 2) % 2;
			}
		}
		if (ops < mmin) {
			mmin = ops;
		}
	}
	cout << mmin << endl;
	

	return 0;
}
