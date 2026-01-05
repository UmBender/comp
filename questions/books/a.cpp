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
	i32 n, t;
	cin >> n >> t;
	vector<i64> a(n);
	for (i32 i = 0; i < n; i++) {
		cin >> a[i];
	}
	i32 left = 0, right = 0;
	i32 acc = 0;
	i32 mmax = 0;
	while(left < n && right < n) {
		if (acc + a[right] <= t) {
			acc += a[right];
			right++;
			mmax = max(right - left, mmax);
		} else {
			acc -= a[left];
			left++;
		}
	}
	cout << mmax << endl;

	return 0;
}
