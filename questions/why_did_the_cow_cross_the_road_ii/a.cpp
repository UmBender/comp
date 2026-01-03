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

void setIO(string name ="") {
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	setIO("maxcross");
	i32 n, k, b;
	cin >> n >> k >> b;
	vector<bool> a(n);
	for (i32 i = 0; i < b; i++) {
		i32 pos;
		cin >> pos;
		pos--;
		a[pos] = true;
	}
	vector<i64> pref(n + 1);
	for (i32 i = 0; i < n; i++) {
		pref[i + 1] = pref[i] + a[i];
	}
	i32 minimal = INT32_MAX;
	for (i32 i = 0; i + k - 1 < n; i++) {
		i32 actual = pref[i + k] - pref[i];
		minimal = min(minimal, actual);
	}
	cout << minimal << endl;


	return 0;
}
