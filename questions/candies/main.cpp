#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int MOD = 1e9 + 7;


struct BIT {
	int n;
	vector<int> t;
	BIT(int n): n(n + 1), t(n + 1) {}
	inline void update(int r, int delta) {
		for (r++; r < n; r += (-r&r)) {
			t[r] += delta;
			t[r] %= MOD;
		}
	}

	inline void update(int l, int r, int delta) {
		update(l, delta);
		update(r + 1, -delta);

	}


	inline int query(int r) {
		int acc = 0;
		for (r++; r > 0; r -= (-r&r)) {
			acc += t[r];
			acc %= MOD;
		}
		return acc;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<BIT> dp(n + 1, BIT(k + 1));
	dp[0].update(0, 0, 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			int begin = j;
			int end = min(j + a[i], k); 
			int actualCount = dp[i].query(j);
			dp[i + 1].update(begin, end, actualCount);
		}
	}

	cout << dp[n].query(k) << endl;


	return 0;
}
