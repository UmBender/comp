#include <bits/stdc++.h>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using i128 = __int128;
using VI = vector<i32>;
using VVI = vector<VI>;
using PII = pair<i32, i32>;
using VII = vector<PII>;
using VVII = vector<VII>;


i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	i64 n;
	cin >> n;
	vector<i64> counter (n + 1);
	for (i32 i = 1; i * i <= n; i++) {
		for (i32 j = i + 1; j * j <= n; j++) {
			if (i * i + j * j > n){
				break;
			}
			counter[i * i + j * j] ++;
		}
	}
	i64 count = 0;
	for (i32 i = 1; i <= n; i++) {
		if (counter[i] == 1) {
			count++;
		}
	}
	cout << count << endl;
	for (i32 i = 1; i <= n; i++) {
		if (counter[i] == 1) {
			cout << i << " ";
		}
	}
	cout << endl;
	
	return 0;
}

