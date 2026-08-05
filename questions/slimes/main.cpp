#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll


static constexpr int MAX_N = 410;
struct Option {
	int sum;
	int cost = 1e18;
};
Option dp[MAX_N][MAX_N];


int32_t main(void) {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		dp[i][i].sum = a[i];
		dp[i][i].cost = 0;
	}

	for (int l = 2; l <= n; l++) {
		for (int i = 0; i + l - 1 < n; i++) {
			for (int k = i; k <= i + l - 1; k++) {
				dp[i][i + l - 1].cost = min(dp[i][i + l - 1].cost, dp[i][k].cost + dp[k + 1][i + l - 1].cost + dp[i][k].sum + dp[k + 1][i + l - 1].sum);
				dp[i][i + l - 1].sum = dp[i][k].sum + dp[k + 1][i + l - 1].sum;
			}
		}
	}
	cout << dp[0][n - 1].cost << endl;

	return 0;
}
