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


i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	i32 n;
	cin >> n;
	vector<pair<i32,i32>> ab(n);
	for (i32 i = 0; i < n; i++) {
		i32 a, b;
		cin >> a >> b;
		ab[i] = {a, -b};
	}
	sort(ab.begin(), ab.end());

	vector<i32> path;
	for (auto p: ab) {
		i32 b = -p.second;
		auto it = lower_bound(path.begin(), path.end(), b);
		if (it == path.end()) {
			path.push_back(b);
		} else {
			*it = b;
		}
	}
	cout << path.size() << endl;
	return 0;
}

