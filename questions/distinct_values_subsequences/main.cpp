#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MOD = (int)1E9 + 7;

signed main() {
	int n;
	cin >> n;
	map<int, int> counter;
	for (int i = 0; i < n; i++) {
		int actual;
		cin >> actual;
		counter[actual]++;
	}
	int c = 1;
	for (auto &[_, x] : counter) {
		c *= (x + 1);
		c %= MOD;
	}
	c += MOD;
	c--;
	c %= MOD;

	cout << c << endl;
}
