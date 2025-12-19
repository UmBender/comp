#include <bits/stdc++.h>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using VI = vector<i32>;
using VVI = vector<VI>;
using PII = pair<i32, i32>;
using VII = vector<PII>;
using VVII = vector<VII>;

void solution();

i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	i32 t;
	cin >> t;
	while (t--) {
		solution();
	}
	return 0;
}


void show_result(vector<i64> result) {
	for(i32 i = 0; i < result.size(); i ++) {
		cout << result[i] << " \n"[i == result.size()-1];
	}	
}
void solution() {
	i64 n, k;
	cin >> n >> k;
	vector<i64> result(k, n);
	if(k % 2 == 1) {
		show_result(result);
		return;
	}
	i64 next_change= 0;
	fill(result.begin(), result.end(), 0ll);
	

	for(i32 bit = 31; bit >= 0; bit--) {
		i64 actual = (n >> bit) & 1;
		if(actual) {
			for(i32 i = 0; i < k; i++) {
				if(i != min(next_change, k - 1)) {
					result[i] += 1ll << bit;
				}
			}
			if(next_change < k) {
				next_change++;
			}

		} else {
			for(i32 i = 0; i < (next_change / 2) * 2; i++) {
				result[i] += (1ll << bit);
			}	
		}
	}
	show_result(result);
	

}
