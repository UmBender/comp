#include <bits/stdc++.h>
using namespace std;
using ll = long long;


static constexpr int MAX_N = 5010;
int dp[MAX_N][MAX_N];

int32_t main(void) {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = 1e9;
		}
	}
	for (int i = 0; i < n; i++) {
		dp[i][i] = 0;
	}
	for (int i = 0; i < n - 1; i++) {
		dp[i][i + 1] = a[i] == a[i + 1] ? 0 : 1;
	}

	for (int l = 2; l < n; l++) {
		for (int i = 0; i + l < n; i++) {
			int j = l + i;
			dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
			dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
			if (a[i] == a[j]) {
				dp[i][j] = min(dp[i][j], dp[i + 1][j - 1] + 1);
			}
			if (a[i] == a[i + 1]) {
				dp[i][j] = min(dp[i][j], dp[i + 1][j]);

			}
			if (a[j] == a[j - 1]) {
				dp[i][j] = min(dp[i][j], dp[i][j - 1]);

			}

		}
	}
	cout << dp[0][n - 1] << endl;
	return 0;
}
