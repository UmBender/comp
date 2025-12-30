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
	vector<i64> w(2 * n);
	for (i32 i = 0; i < 2 * n; i++) {
		cin >> w[i];
	} 
	sort(w.begin(), w.end());
	i64 minimal = 1e18;
	for (i32 i = 0; i < 2 * n; i++) {
		for (i32 j = 0; j < 2 * n; j++) {
			if(j == i) {
				continue;
			}
			vector<i64> temp;
			temp.reserve(2 * n);
			for (i32 k = 0; k < 2 * n; k++) {
				if(k == i || j == k) {
					continue;
				}
				temp.push_back(w[k]);
			}
			i64 acc = 0;
			for (i32 k = 0; k <  temp.size(); k+=2) {
				acc += abs(temp[k] - temp[k + 1]);
			}
			minimal = min(minimal, acc);

		}
	}
	cout << minimal << "\n";
	return 0;
}
