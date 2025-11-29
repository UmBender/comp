#include<bits/stdc++.h>
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
	i32 n;
	cin >> n;
	VI a(2 * n);
	for(i32 i{0}; i < 2*n; i++) {
		cin >> a[i];
	}
	map<i32, i32> mp;
	for(i32 i{0}; i < 2 * n; i++) {
		mp[a[i]]++;
	}
	i32 odd = 0;
	for(auto [k, v]: mp) {
		if(v % 2 == 1) {
			odd++;
		}
	}

	i32 even = mp.size() - odd;
	i32 mmax = min(even, max(n - odd/2, 0));
	if(((n - mmax) % 2 == 1) && odd == 0) {
		mmax--;
		mmax = max(mmax, 0);
	}


	cout << odd + 2 * mmax << endl;

}
