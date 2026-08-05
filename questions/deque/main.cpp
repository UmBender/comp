#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static constexpr ll MAX_N = 3010;

struct Option {
	ll last;
	ll actual;
};

Option dp[MAX_N][MAX_N];





int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0; i < n; i++) {
		dp[i][i].actual = a[i];
		dp[i][i].last = 0;
	}
	for (int l = 2; l <= n; l++) {
		for (int i = 0; i + l - 1 < n; i ++) {
			ll first = dp[i + 1][i + l - 1].last + dp[i][i].actual;
			ll second = dp[i][i + l - 2].last + dp[i + l - 1][i + l - 1].actual;
			if (first > second) {
				dp[i][i + l - 1].actual = first;
				dp[i][i + l - 1].last = dp[i + 1][i + l - 1].actual;
			} else {
				dp[i][i + l - 1].actual = second;
				dp[i][i + l - 1].last = dp[i][i + l - 2].actual;
			}
		}
	}

	cout << dp[0][n - 1].actual - dp[0][n - 1].last << endl;

	return 0;
}
