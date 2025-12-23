#include<bits/stdc++.h>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
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
	i32 n;
	cin >> n;
	vector<i32> a(n);
	for(i32 i = 0; i < n; i++) {
		cin >> a[i];
	}
	i32 computed = 0;
	for(i32 i = 0; i < n - 1; i ++) {
		computed += abs(a[i] - a[i + 1]);
	}
	i32 minimal = 110 * (2e5 + 100);

	minimal = min(minimal, 
			computed - abs(a[0] - a[1]));

	for(i32 i = 1; i < n - 1; i++) {
		i32 must_remove = abs(a[i - 1] - a[i]) +
			abs(a[i] - a[i + 1]);
		i32 must_add = abs(a[i - 1] - a[i + 1]);
		minimal = min(minimal, computed - must_remove + must_add);
	}
	minimal = min(minimal,
			computed - abs(a[n - 1] - a[n - 2]));

	minimal = min(computed, minimal);

	cout << minimal << endl;
}
