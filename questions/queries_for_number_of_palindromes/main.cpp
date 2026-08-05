#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static constexpr int MAX_N = 5010;

struct Option {
	bool actual;
	int counter;
};

Option dp[MAX_N][MAX_N];


int32_t main(void) {
	cin.tie(0)->sync_with_stdio(0);
	string s;
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i++) { 
		dp[i][i].actual = true;
		dp[i][i].counter = 1;
	}

	for (int i = 0; i < n - 1; i++) {
		dp[i][i + 1].actual = s[i] == s[i + 1];
		dp[i][i + 1].counter = 2 + (s[i] == s[i + 1] ? 1 : 0);
	}

	for (int l = 3; l <= n; l++) {
		for (int i = 0; i + l - 1 < n; i++) {
			dp[i][i + l - 1].actual = dp[i + 1][i + l - 2].actual && s[i] == s[i + l - 1];
			dp[i][i + l - 1].counter = dp[i + 1][i + l - 1].counter + dp[i][i + l - 2].counter;
			dp[i][i + l - 1].counter -= dp[i + 1][i + l - 2].counter;
			dp[i][i + l - 1].counter += dp[i][i + l - 1].actual ? 1 : 0;
		}
	}
/*	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			cout << format("i: {}, j: {}, dp: {}\n", i, j, dp[i][j].counter);
		}
	}
	return 0;
	*/
	int q;
	cin >> q;
	while (q--) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		cout << dp[a][b].counter << endl;
	}

	return 0;
}
