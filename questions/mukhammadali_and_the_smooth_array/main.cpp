#include <bits/stdc++.h>
using namespace std;
#define int int64_t

void solution();
signed main() {
	int t;
	cin >> t;
	while (t--) solution();
}
void solution() {
	int n;
	cin >> n;
	int a[n], c[n];
	for (int i = 0; i < n; i++) { cin >> a[i]; }
	for (int i = 0; i < n; i++) { cin >> c[i]; }
	int dp[n];
	int cost = 0;

	for (int i = 0; i < n; i++) {
		dp[i] = c[i];
		cost += c[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] <= a[j]) { dp[i] = max(dp[i], dp[j] + c[i]); }
		}
	}
	int mmax = 0;
	for (int i = 0; i < n; i++) {
		mmax = max(mmax, dp[i]);
	}

	cout << cost - mmax << endl;
}
