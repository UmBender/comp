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
	i32 n;cin >> n;
	vector<i64> a(n),b(n);
	for(i32 i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(i32 i = 0; i < n; i++) {
		cin >> b[i];
	}
	i64 first = 0, second = 0;
	for(i32 i = 0; i < n; i++) {
		i64 temp_max = INT64_MIN;
		i64 temp_min = INT64_MAX;
		temp_max = max(temp_max, first - a[i]);
		temp_max = max(temp_max, second - a[i]);
		temp_max = max(temp_max, b[i] - first);
		temp_max = max(temp_max, b[i] - second);

		temp_min = min(temp_min, first - a[i]);
		temp_min = min(temp_min, second - a[i]);
		temp_min = min(temp_min, b[i] - first);
		temp_min = min(temp_min, b[i] - second);
		first = temp_max;
		second = temp_min;	
	}
	cout << first << endl;

}

