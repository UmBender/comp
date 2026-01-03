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
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}


i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	setIO("bcount");
	i32 n, q;
	cin >> n >> q;
	vector<i32> ids(n);
	for (i32 i = 0; i < n; i++) {
		cin >> ids[i];
	}
	array<vector<i64>, 4> pref;
	for (i32 i = 1; i <= 3; i++) {
		pref[i] = vector<i64>(n + 1);
	}
	for (i32 i = 0; i < n; i++) {
		for (i32 j = 1; j <= 3; j++) {
			pref[j][i + 1] = pref[j][i] + (j == ids[i]);
		}
	}
	while(q--) {
		array<i64, 4> ans;
		i32 l, r;
		cin >> l >> r;
		l--;
		for (i32 i = 1; i <= 3; i++) {
			ans[i] = pref[i][r] - pref[i][l];
		}
		for (i32 i = 1; i <= 3; ++i) {
			cout << ans[i] << " \n"[i == 3];
		}

	}
	
	return 0;
}
