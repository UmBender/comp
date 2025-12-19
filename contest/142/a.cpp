#include<bits/stdc++.h>
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
	i64 l, a, b; cin >> l >> a >> b;
	set<i64> nums;
	i64 mmax = a;
	while(!nums.count(a)) {
		nums.insert(a);
		mmax = max(mmax, a);
		a +=b;
		a %= l;
	}
	cout << mmax << endl;
}
