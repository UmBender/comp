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

void setIO(string name ="") {
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}

}
i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	setIO("pairup");
	i32 n;
	cin >> n;
	vector<pair<i32,i32>> xy(n);
	for (i32 i = 0; i < n; i++) {
		auto &[y, x] = xy[i];
		cin >> x >> y;
	}
	sort(xy.begin(), xy.end());
	i32 left = 0, right = n - 1;
	i32 mmax = 0;
	while(left < right) {
		auto &[yleft, xleft]  = xy[left];
		auto &[yright, xright] = xy[right];
		if (xleft < xright) {
			mmax = max(mmax, yleft + yright);
			xright -= xleft;
			xleft = 0;
			left++;
		} else if (xleft > xright) {
			mmax = max(mmax, yleft + yright);
			xleft -= xright;
			xright = 0;
			right--;
		} else if (xleft == xright) {
			mmax = max(mmax, yleft + yright);
			xleft = 0;
			xright = 0;
			left ++, right--;
		}
	}
	if (right == left) {
		mmax = max(mmax, xy[left].second + xy[right].second);
	}
	cout << mmax << endl;
	
	return 0;
}
