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
	solution();
	return 0;
}

const i64 MAX = 31;

void solution() {
	i32 n, q;
	cin >> n >> q;
	vector<i64> a(n + 1);
	for (i32 i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vector<array<i64, MAX>> bl(n + 1);
	vector<array<i64, MAX>> sum(n + 1);

	for (i32 i = 1; i <= n; i++) {
		bl[i][0] = a[i];
		sum[i][0] = i;
	}

	for (i32 hh = 1; hh < MAX; hh++) {
		for (i32 i = 1; i <= n; i++) {
			bl[i][hh] = bl[bl[i][hh - 1]][hh - 1];
			sum[i][hh] = sum[i][hh - 1] + sum[bl[i][hh - 1]][hh - 1];
		}
	}

	while (q--) {
		i64 t, b;
		cin >> t >> b;
		i64 acc = 0;
		for (i32 i = 0; i < MAX; i++) {
			if ((t >> i) & 1) {
				acc += sum[b][i];
				b = bl[b][i];
			}
		}
		cout << acc << endl;
	}
}
