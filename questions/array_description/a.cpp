// clang-format off
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
void __dbg() { cerr << endl; }
template <typename T> void __dbg(T t) { cerr << t << endl; }
template <typename T, typename... TRest> void __dbg(T first, TRest... rest) {
  cerr << first << ", ";
  __dbg(rest...);
}
#define dbg(...)                                                               \
  do {                                                                         \
    cerr << "DBG> " << "(" << #__VA_ARGS__ << ") = ";                          \
    __dbg(__VA_ARGS__);                                                        \
  } while (0)
#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
using ld = long double;
#define int ll
// clang-format on

const int MOD = 1E9 + 7;
void solution() {
	int n, m;
	cin >> n >> m;
	vector<int> x(n);
	for (auto &i : x) { cin >> i; }
	vector<vector<int>> dp(n, vector<int>(m + 1, 0));
	for (int i = 0; i <= m; i++) { dp[0][i] = 1; }
	for (int i = 0; i < n - 1; i++) {
		if (x[i] != 0) {
			int actual = dp[i][x[i]];
			fill(dp[i].begin(), dp[i].end(), 0);
			dp[i][x[i]] = actual;
		}
		for (int j = 1; j < m + 1; j++) {
			if (j - 1 >= 0) {
				dp[i + 1][j - 1] += dp[i][j];
				dp[i + 1][j - 1] %= MOD;
			}
			dp[i + 1][j] += dp[i][j];
			dp[i + 1][j] %= MOD;

			if (j + 1 < m + 1) { 
				dp[i + 1][j + 1] += dp[i][j]; 
				dp[i + 1][j + 1] %= MOD; 
				
			}
		}
	}

	int possi = 0;
	if (x.back() == 0) {
		for (int i = 1; i < m + 1; i++) {
			if (dp.back()[i] != 0) { possi += dp.back()[i]; 
				possi %= MOD;
			}
		}
	} else {
		possi = dp.back()[x.back()];

	}

	cout << possi << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	solution();

	return 0;
}
