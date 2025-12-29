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
	i32 t;
	cin >> t;
	while(t--) {
		solution();
	}
	return 0;
}

void solution() {
	i64 a, b;
	cin >> a >> b;
	i32 max_layers = 0;
	for (i32 n = 1; n <= 63; n++) {
		i64 sum1 = 0;
		i64 sum2 = 0;
		for (i32 i = 0; i < n; i++) {
			if (i % 2 == 0) {
				sum1 += (1ll << i);
			} else {
				sum2 += (1ll << i);
			}
		}
		if ((a >= sum1 && b >= sum2) || (a >= sum2 && b >= sum1)) {
			max_layers = n;
		} else {
			break;
		}
	}
	cout << max_layers << endl;
}

