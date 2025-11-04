#include <bits/stdc++.h>
using namespace std;
#define int64_t

void solution();
signed main() { solution(); }
void solution() {
	int n, x;
	cin >> n >> x;
	int w[n];
	for (auto &i : w) { cin >> i; }
	int mmax = (1ll << n) - 1;
	vector<pair<int, int>> dp((1ll << n), {n + 1, x - 1});
	dp[0] = {0, 0};

	for (int j = 0; j <= mmax; j++) {
		for (int i = 0; i < n; i++) {
			pair<int, int> builded = {dp[j].first, dp[j].second + w[i]};
			if (builded.second > x) {
				builded.first++;
				builded.second = min(dp[j].second, w[i]);
			}
			dp[j | (1ll << i)] = min(dp[j | (1ll << i)], builded);
		}
	}
	if (dp.back().second > 0) { dp.back().first++; }
	cout << dp.back().first << endl;
}
