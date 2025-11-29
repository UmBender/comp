#include<bits/stdc++.h>
#include <cstdint>
using namespace std;

using i64 = int64_t;
using i32 = int32_t;
using i128 = __int128;
using VI = vector<i32>;
using VVI = vector<VI>;
using PII = pair<i32,i32>;
using VII = vector<PII>;
using VVII = vector<VII>;

void solution();
i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	i32 t;
	cin >> t;
	while(t--) {
		solution();
	}
	return 0;
}

void solution() {
	i64 n, k;
	cin >> n >> k;
	vector<i64> a(n), b(n);
	for(i64 &i: a) {cin >> i;}
	for(i64 &i: b) {cin >> i;}
	vector<i64> left(n), right(n);
	i64 acc = INT64_MIN, mmax = INT64_MIN;

	acc = a[0];
	left[0] = acc;
	mmax = acc;

	for(i32 i = 1; i < n; i++){
		acc = max(a[i], acc + a[i]);
		left[i] = acc;
		mmax = max(mmax, acc);
	}
	i64 base = mmax;

	acc = a[n-1];
	right[n-1] = acc;
	for(i32 i = n - 2; i >= 0; i--) {
		acc = max(a[i], acc + a[i]);
		right[i] = acc;
	}

	if(k % 2 ==0) {
		cout << base << endl;
		return;
	}


	i64 more = INT64_MIN;
	for(i32 i= 0; i < n; i++) {
		i64 inc = left[i] + right[i] - a[i];
		more = max(more, inc + b[i]);
	}

	i64 ans = max(base, more);
	cout << ans << endl;
}
