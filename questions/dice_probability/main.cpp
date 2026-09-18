#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define int ll
#define endl "\n"


int32_t main() {
	int n;
	cin >> n;
	vector<vector<ld>> dp(n + 1, vector<ld>(n * 6 + 1));
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j + 6 < dp[0].size(); j++) {
			for (int k = 1; k <= 6 && k + j < dp[0].size(); k++) {
				dp[i][j + k] += dp[i - 1][j];
			}
		}
	}

	ld total = accumulate(begin(dp[n]), end(dp[n]), 0.0l);

	int a, b;
	cin >> a >> b;

	ld interval = accumulate(begin(dp[n]) + a, begin(dp[n]) + b + 1, 0.0l);

	cout << fixed << setprecision(6) << interval / total << endl;
	return 0;

}
