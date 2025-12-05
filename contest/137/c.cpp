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
	i64 n, k;
	cin >> n >> k;
	vector<i64> a(n);
	for(i32 i = 0; i < n; i++) {
		cin >> a[i];
	}
	ranges::sort(a);
	set<i64> exists;
	set<i64> used;
	set<i64> sol;

	for(i64 i: a) {
		exists.insert(i);
	}

	for(i64 i = 0; i < n; i++) {
		if(used.count(a[i])){ 
			continue;
		}
		if(k / a[i] > (i64)1e6 +100) {
			cout << -1 << endl;
			return;
		}
		for(i64 j = a[i]; j <=k; j+=a[i]) {
			if(!exists.count(j)) {
				cout << - 1<< endl;
				return;
			}
			if(!used.count(j)) {
				used.insert(j);
			}
		}
		sol.insert(a[i]);
	}
	cout << sol.size() << '\n';
	for(auto i: sol) {
		cout << i << " ";
	}
	cout << '\n';
}
