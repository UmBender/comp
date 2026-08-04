#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll


static constexpr int MAX_N = 5010;
static constexpr int DECIDED = 0;
static constexpr int NDECIDED = 1;
int dp[MAX_N][MAX_N][2];
bool calc[MAX_N][MAX_N];

int32_t main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& ai: a) {
		cin >> ai;
	}
	for (int i = 0; i < n; i++) {
		dp[i][i][DECIDED] = a[i];
		calc[i][i] = true;
	}

	function<void(int,int)> rec;
	rec = [&](int l, int r) {
		if (calc[l][r]) {
			return;
		}
		if (l == r) {
			return;
		}
		rec(l + 1, r);
		rec(l, r - 1);
		calc[l][r] = true;
		if (dp[l + 1][r][NDECIDED] + a[l] > dp[l][r - 1][NDECIDED] + a[r]) {
			dp[l][r][DECIDED] = dp[l + 1][r][NDECIDED] + a[l];
			dp[l][r][NDECIDED] = dp[l + 1][r][DECIDED];
		} else {
			dp[l][r][DECIDED] = dp[l][r - 1][NDECIDED] + a[r];
			dp[l][r][NDECIDED] = dp[l][r - 1][DECIDED];
		}

		return;
	};

	rec(0, n - 1);
	int ans = dp[0][n - 1][DECIDED];
	cout << ans << endl;


	return 0;
}
