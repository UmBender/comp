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

void solution() {
	i64 n;
	cin >> n;
	vector<i64> a(n), b(n), c(n);
	for (i32 i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (i32 i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (i32 i = 0; i < n; i++) {
		cin >> c[i];
	}
	auto count_valid = [&](vector<i64> &first, vector<i64> &second) {
		i64 valid_count = 0;
		for (i32 s = 0; s < n; s++) {
			bool ok = true;
			for (i32 i = 0; i < n; i++) {
				if (first[i] >= second[(i + s) % n]) {
					ok = false;
					break;
				}
			}
			if (ok)
				valid_count++;
		}
		return valid_count;
	};
	i64 first = count_valid(a, b);
	i64 second = count_valid(b, c);
	cout << (i64)n * first * second << endl;
}
