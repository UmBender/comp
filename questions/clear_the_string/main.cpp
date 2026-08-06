#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static constexpr int MAX_N = 510;


int dp[MAX_N][MAX_N];



int32_t main(void) {
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n;i ++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = 1e9;
		}

		dp[i][i] = 1;
	}

	
	for (int i = 0; i < n - 1; i++) {
		dp[i][i + 1] = 2;
		if(s[i] == s[i + 1]) {
			dp[i][i + 1] = 1;
		}
	}

	for (int l = 3; l <= n; l++) {
		for (int i = 0; i + l - 1 < n; i++) {
			if (s[i] == s[i + l - 1]) {
				dp[i][i + l - 1] = min(dp[i][i + l - 1], dp[i][i + l - 2]);
				dp[i][i + l - 1] = min(dp[i][i + l - 1], dp[i + 1][i + l - 1]);

			}
			dp[i][i + l - 1] = min(dp[i][i + l - 1], dp[i][i + l - 2] + 1);
			dp[i][i + l - 1] = min(dp[i][i + l - 1], dp[i + 1][i + l - 1] + 1);
			for (int j = i; j < i + l - 1; j++) {
				dp[i][i + l - 1] = min(dp[i][i + l - 1], dp[i][j] + dp[j + 1][i + l - 1]);
			}
		}	
	}
	cout << dp[0][n - 1] << endl;
}
