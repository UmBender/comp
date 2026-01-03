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
	i32 n;
	cin >> n;

	vector<i64> a(n);
	for (i32 i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<i64> pref(n), suf(n);

	pref[0] = a[0];
	for (i32 i = 1; i < n; i++) {
		pref[i] = gcd(pref[i - 1], a[i]);
	}

	suf[n - 1] = a[n - 1];
	for (i32 i = n - 2; i >= 0; i--) {
		suf[i] = gcd(suf[i + 1], a[i]);
	}

	i64 mmax = max(pref[n - 2], suf[1]);
	for (i32 i = 1; i < n - 1; i++) {
		i64 left = pref[i - 1];
		i64 right = suf[i + 1];
		mmax = max(mmax, gcd(left, right));
	}

	cout << mmax << endl;
	return 0;
}
