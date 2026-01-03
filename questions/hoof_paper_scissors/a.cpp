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
	setIO("hps");
	i32 n;
	cin >> n;
	map<char,i32> mp = {{'P', 0}, {'H', 1}, {'S', 2}};
	array<vector<i32>, 3> pref; 
	for (i32 i = 0; i < 3; i++) {
		pref[i] = vector<i32>(n + 1);
	}
	for (i32 i = 0; i < n; i++) {
		char input;
		cin >> input;
		for (i32 j = 0; j < 3; j++) {
			pref[j][i + 1] = pref[j][i] + (mp[input] == j);
		}
	}
	i64 mmax = 0;
	vector<pair<i32,i32>> combs;
	for (i32 i = 0; i < 3; i++) {
		for (i32 j = 0; j < 3; j++) {
			combs.emplace_back(i, j);
		}
	}
	for (i32 i = 0; i < n; i++) {
		for (auto [f, s]: combs) {
			i64 first = pref[f][i];
			i64 second = pref[s][n] - pref[s][i];
			i64 sum = first + second;
			mmax = max(sum, mmax);
		}	
	}

	cout << mmax << endl;
	return 0;
}

