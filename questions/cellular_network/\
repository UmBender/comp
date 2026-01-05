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

i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	i32 n, m;
	cin >> n >> m;
	vector<i64> a(n), b(m);
	for (i32 i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (i32 i = 0; i < m; i++) {
		cin >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	i64 left = 0, right = 1e12;
	i64 radius = 1e12 + 100;

	auto check = [&](i64 temp_radius) -> bool {
		i32 i = 0, j = 0;
		i32 counter = 0;
		while (i < n && j < m) {
			i64 bl = b[j] - temp_radius, br = b[j] + temp_radius;
			if (a[i] >= bl && a[i] <= br) {
				i ++;
				counter++;
			} else if(br < a[i]) {
				j++;
			} else {
				return false;
			}
		}
		return counter == n;

	};
	while (left <= right) {
		i64 t = left + (right - left) / 2;
		if (check(t)) {
			radius = min(radius, t);
			right = t - 1;
		} else {
			left = t + 1;
		}
	}
	cout << radius << endl;

	return 0;
}
