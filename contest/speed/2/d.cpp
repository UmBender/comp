# include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i32 = int32_t;
using i128 = __int128;
using VI = vector<i32>;
using VVI = vector<VI>;
using PII = pair<i32, i32>;
using VII = vector<PII>;
using VVII = vector<VII>;
// debug stuff, no need to type at first
void PRINT(auto x) { cerr << '\t' << x << endl; }
void PRINT(const char *name, auto... x) {
	cerr << "DEBUG> "<< name << " = [" << endl;
	(PRINT(x), ...);
	cerr << ']' << endl;
}
# define DEBUG(...) PRINT(#__VA_ARGS__, __VA_ARGS__)
// #define int i64
const i64 MOD = 998244353;
i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	i32 n;
	cin >> n;
	vector<i64> a(n), b(n);
	for (i32 i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (i32 i = 0; i < n; i++) {
		cin >> b[i];
	}
	i64 base = 1;
	vector<vector<i64>> dp(n,vector<i64>(3010));
	for (i32 i = 0; i < 3010; i++) {
		if (i >= a[0] && i <= b[0]) {
			dp[0][i] = 1;
		}
	}
	for (i32 i = 1; i < n; i++) {
		i64 acc = 0;
		for (i32 j = 0; j < 3010; j++) {
			acc += dp[i - 1][j] ;
			acc %= MOD;
			if (j >= a[i] && j <= b[i]) {
				dp[i][j] = acc;
			}
		}
	}
	i64 sum = 0;
	for (i32 i = 0; i < 3010; i++) {
		sum += dp.back()[i];
		sum %= MOD;
	}
	cout << sum << endl;
	return 0;
}

