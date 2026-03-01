#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <array>
#include <tuple>
#include <functional>
#include <numeric>

using namespace std;
using i32 = int;
using i64 = long long;
using i128 = __int128;
using VI = vector<i32>;
using VVI = vector<VI>;
using PII = pair<i32,i32>;
using VII = vector<PII>;
using VVII = vector<VII>;

const int MAX_N = 11;
const int MAX_POSSIBLE_N = 1ll << MAX_N;
const int MAX_M = 1010;
const int MOD = 1e9 + 7;

array<array<int,2020>, 1010 > dp;

i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;

	for (auto &actual: dp) {
		fill(actual.begin(), actual.end(), -1);
	}


	dp[0][0] = 1;
	function<void(int, int, int, vector<int> &)> gen;
	gen = [&](int j, int fmask, int smask, vector<int>& masks) -> void {
		if (j == n) {
			masks.push_back(smask);
			return;
		}

		if (j + 1 < n && (0 == ((fmask >> j) & 3))) {
			gen(j + 2, fmask, smask, masks);
		}

		if (0 == ((fmask >> j) & 1)) {
			gen(j + 1, fmask, smask + (1 << j), masks);
		}

		if (0 != ((fmask >> j) & 1)) {
			gen(j + 1, fmask, smask, masks);
		}
	};
	
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j < (1 << n); j++) {
			if (dp[i][j] == -1) {
				continue;
			}

			vector<int> nexts;
			gen(0, j, 0, nexts);
			for (auto next: nexts) {
				if(dp[i + 1][next] == -1) {
					dp[i + 1][next] = dp[i][j];
				} else {
					dp[i + 1][next] = dp[i + 1][next] + dp[i][j];
					dp[i + 1][next] %= MOD;
				}
			}
		}	
	}

	int ans = max(dp[m][0], 0);
	cout << ans << endl;


	return 0;
}
