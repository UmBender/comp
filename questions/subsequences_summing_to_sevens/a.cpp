#include <bits/stdc++.h>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using i128 = __int128;
using VI = vector<i32>;
using VVI = vector<VI>;
using PII = pair<i32, i32>;
using VII = vector<PII>;
using VVII = vector<VII>;

void setIO(string name = "") {
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	setIO("div7");
	i32 n; 
	cin >> n;
	vector<i64> id(n);
	for (i32 i = 0; i < n; ++i) {
		cin >> id[i];
	}
	vector<i64> pref(n + 1);
	for (i32 i = 0; i < n; i++) {
		pref[i + 1] = pref[i] + id[i];
	}
	i32 counter = 0;
	for (i32 i = 0; i < n; ++i) {
		for (i32 j = i + 1; j <= n; ++j) {
			if((pref[j] - pref[i]) % 7 == 0) {
				counter = max(counter, j - i);
			}
			
		}
	}
	cout << counter << endl;
	return 0;
}
