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
i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	i32 n;
	cin >> n;
	vector<pair<i32,i32>> a(n);
	for (i32 i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(), a.end());
	i32 mmin = INT32_MAX;
	set<pair<i32,i32>> deltas;
	for (i32 i = 0; i < n; i++) {
		for (i32 j = 0; j < n; j++) {
			if (i == j) {
				continue;
			}
			i32 dx = a[j].first - a[i].first;
			i32 dy = a[j].second - a[i].second;
			i32 g = gcd(abs(dx), abs(dy));
			dx /= g;
			dy /= g;
			if (!deltas.count({dx, dy})) {
				deltas.insert({dx, dy});
			}

			if (!deltas.count({-dx, -dy})) {
				deltas.insert({-dx, -dy});
			}
				
		}
	}

	cout << deltas.size() << endl;


	return 0;
}
