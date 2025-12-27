#include <bits/stdc++.h>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using i128 = __int128;
using VI = vector<i32>;
using VVI = vector<VI>;
using PII = pair<i32,i32>;
using VII = vector<PII>;
using VVII = vector<VII>;

void solution();

i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	solution();
	return 0;
}

void solution() {
	i32 n;
	cin >> n;
	vector<vector<i64>> abc(3, vector<i64>(n));
	for(i32 i = 0; i < 3; i++) {
		for(i32 j = 0; j < n; j++) {
			cin >> abc[i][j];
		}
	}
	vector<vector<i64>> pref(3, vector<i64>(n + 1));
	for(i32 i = 0; i < 3; i++) {
		for(i32 j = 0; j < n; j++) {
			pref[i][j + 1] = pref[i][j] + abc[i][j];
		}

	}
	i64 mmax = -1e9;
	i64 ans = -1e9;
	for(i32 i = 2; i <= n - 1; i++) {
		i64 first = pref[0][i-1] - pref[1][i-1];
		mmax = max(mmax, first);
		i64 second = pref[1][i] - pref[2][i];
		ans = max(ans, mmax + second);
	}
	ans += pref[2][n];
	cout << ans << endl;
}

