#include <bits/stdc++.h>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
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
	i32 n, l, r;
	cin >> n >> l >> r;
	vector<i64> a(n);
	vector<i64> pref(n + 1);
	l--,r--;
	i64 acc = 0;
	i64 m = 1;
	i64 ntouch = 1ll << 29;
	i64 in_left = 0;
	for(i32 i = 0; i < n; i++, m++) {
		pref[i] = acc;
		if(i == r) {
			i64 actual = pref[l] ^ pref[i] ^ ntouch;
			a[i] = actual;
			acc ^= actual ^ ntouch;
			continue;
		}
		if(m == acc) {
			m++;
		}
		i64 new_value = acc ^ m;
		a[i] = new_value;
		acc ^= new_value;
		if(l == i) {
			a[i] ^= ntouch;
		}

	}
	for(i32 i = 0; i < n; i++) {
		cout << a[i] << " \n"[i == n-1];
	}
	
	
}

