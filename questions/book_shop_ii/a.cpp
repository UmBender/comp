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

#define int i64
i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, x;
	cin >> n >> x;
	vector<tuple<int, int, int>> hsk(n);
	for (int i = 0; i < n; i++) {
		auto &[h, s, k] = hsk[i];
		cin >> h;
	}

	for (int i = 0; i < n; i++) {
		auto &[h, s, k] = hsk[i];
		cin >> s;
	}

	for (int i = 0; i < n; i++) {
		auto &[h, s, k] = hsk[i];
		cin >> k;
	}

	vector<pair<int, int>> hsk_real;
	for (int i = 0; i < n; i++) {
		auto [h, s, k] = hsk[i];

		int power = 1;
		for (int i = 0; i < 32; i++) {
			int n_h = h * power;
			int n_s = s * power;
			if (k >= power) {
				hsk_real.push_back({n_h, n_s});
				k -= power;
			}
			power *= 2;
		}
		if (k) {
			int n_h = h * k;
			int n_s = s * k;
			hsk_real.push_back({n_h, n_s});
		}
	}

	vector<int> dp(x + 1, INT32_MIN);
	dp[0] = 0;
	for (int i = 0; i < hsk_real.size(); i++) {
		auto [cost, pages] = hsk_real[i];
		for (int j = dp.size() - 1; j >= 0; j--) {
			if (dp[j] == INT32_MIN) {
				continue;
			}
			if (j + cost < dp.size()) {
				dp[j + cost] = max(dp[j + cost], dp[j] + pages);
			}
		}
	}

	int mmax = 0;
	for (int i = 0; i <= x; i++) {
		mmax = max(mmax, dp[i]);
	}
	cout << mmax << endl;

	return 0;
}
