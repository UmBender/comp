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
	set<i32> used;
	i32 mmax = (1ll << n) - 1;
	vector<i32> sol;
	sol.reserve(mmax + 100);
	sol.push_back(mmax);
	used.insert(mmax);
	for(i32 i = n - 1; i >= 0; i--) {
		for(i32 actual =  (1ll << i) - 1; actual < mmax; actual += (1ll << (i))) {
			if(used.count(actual)) continue;
			sol.push_back(actual);
			used.insert(actual);
		}	
	}
	for(i32 i = 0; i < (1ll << n) - 1; i++) {
		if(!used.count(i)) {
			sol.push_back(i);
		}
	}
	i32 size = sol.size();
	for(i32 i = 0; i < size; i++) {
		cout << sol[i] << " \n"[i == size - 1];
	}
}
