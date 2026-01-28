#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using i64 = long long;
using i128 = __int128;



#define int long long
void setIO(string name = "") {
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}	
}
i32 main() {
	setIO("haybales");
	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	for (auto &i: v) { cin >> i; }
	sort(v.begin(), v.end());
	auto query = [&](int left, int right) -> int {
		int size = upper_bound(v.begin(), v.end(), right) - lower_bound(v.begin(), v.end(), left);
		return size;
	};
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		cout << query(l, r) << endl;
	}
	

	return 0;
}

