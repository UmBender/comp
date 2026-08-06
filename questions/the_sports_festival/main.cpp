#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define int ll
static constexpr int MAX_N = 2010;
int dp[MAX_N][MAX_N];


int32_t main(void) {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = 1e18;
		}
		dp[i][i] = 0;
	}
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(begin(a), end(a));
	for (int l = 1; l < n; l++) {
		for (int i = 0; i + l < n; i++) {
			int j = i + l;
			dp[i][j] = min(dp[i][j], dp[i][j - 1] + abs(a[j] - a[i]));
			dp[i][j] = min(dp[i][j], dp[i + 1][j] + abs(a[j] - a[i]));
		}
	}
	cout << dp[0][n - 1] << endl;

	


	return 0;
}
