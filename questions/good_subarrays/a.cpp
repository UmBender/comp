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
	i32 t;
	cin >> t;
	while (t--) {
		solution();
	}
	return 0;
}

void solution() {
	i32 n;
	cin >> n;
	string s;
	cin >> s;
	vector<i32> a(n);
	for (i32 i = 0; i < n; i++) {
		a[i] = s[i] - '0';
	}
	vector<i32> pref (n + 1);
	for (i32 i = 0; i < n; i++) {
		pref[i + 1] = pref[i] + a[i];
	}
	i64 counter = 0;
	map<i64,i64> dp;
	
	for (i32 i = n - 1; i >= 0; i--) {
		dp[pref[i + 1] - i]++;
		counter += dp[pref[i] - i + 1];
	}

	cout << counter << endl;
}
