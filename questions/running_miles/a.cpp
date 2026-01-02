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
	vector<i64> b(n);
	for (i32 i = 0; i < n; i++) {
		cin >> b[i];
	}
	vector<i64> first(n);
	vector<i64> second(n);
	for (i32 i = 0; i < n; i++) {
		first[i] = b[i] + i;
		second[i] = b[i] - i;
	}
	vector<i64> pref(n + 1);
	set<i64> nums;
	nums.insert(second.back());
	
	for (i32 i = n - 2; i >= 0; i--) {
		pref[i] = b[i] + *nums.rbegin();
		if (!nums.count(second[i])) {
			nums.insert(second[i]);
		}
	}
	i64 ans = INT64_MIN;
	i64 mmax = INT64_MIN;
	for (i32 i = 1; i < n - 1; i++) {
		mmax = max(mmax, first[i - 1]);
		i64 actual = pref[i];
		ans = max(ans, actual + mmax);
	}
	cout << ans << endl;
}
