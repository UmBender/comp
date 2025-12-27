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

void solution();

i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	solution();
	return 0;
}

void solution() {
	i32 n,m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	i64 mmin = 1e9;
	for(i32 i = 0; i < n - m + 1; i++) {
		i64 acc = 0;
		for(i32 j = 0; j < m; j++) {
			i32 up = s[i + j] - '0';
			i32 down = t[j] - '0';
			if(up < down) {
				up += 10;
			}
			acc += up - down;
		}
		mmin = min(mmin, acc);
	}
	cout << mmin << endl;
}
