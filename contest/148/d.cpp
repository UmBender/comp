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
	vector<i64> a(n);
	for (i32 i = 0; i < n; i++) {
		cin >> a[i];
	}

	map<i64, map<i64, vector<i64>>> pos;
	i64 counter = 0;
	for (i32 i = 0; i < n; i++) {
		if (a[i] % 3 == 0) {
			pos[a[i] / 3][3].push_back(i);
		}
		if (a[i] % 5 == 0) {
			pos[a[i] / 5][5].push_back(i);
		}
		if (a[i] % 7 == 0) {
			pos[a[i] / 7][7].push_back(i);
		}
	}
	for (auto &[k, v] : pos) {
		if (v[3].empty() || v[5].empty() || v[7].empty()) {
			continue;
		}
		i64 dirty_total = v[3].size() * v[5].size() * v[7].size();
		vector<pair<i32, i32>> sweep_line;
		for (auto i : v[3]) {
			sweep_line.push_back({i, 3});
		}
		for (auto i : v[5]) {
			sweep_line.push_back({i, 5});
		}
		for (auto i : v[7]) {
			sweep_line.push_back({i, 7});
		}
		sort(sweep_line.begin(), sweep_line.end());
		i64 invalid = 0;
		i64 count7 = 0, count3 = 0;
		for (auto &p : sweep_line) {
			i32 type = p.second;
			if (type == 5) {
				i64 count7_r = v[7].size() - count7;
				i64 count3_r = v[3].size() - count3;
				invalid += count7 * count3_r;
				invalid += count7_r * count3;


			} else if (type == 7) {
				count7++;
			} else {
				count3++;
			}
		}
		counter += dirty_total - invalid;
	}
	cout << counter << endl;
	return 0;
}
