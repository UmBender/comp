#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <string>
#include <cstring>

using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
using VI = vector<i32>;
using VVI = vector<VI>;
using PII = pair<i32,i32>;
using VII = vector<PII>;
using VVII = vector<VII>;

#define int i64

const int MAX_M = 1100; 
const int MOD = 1e9 + 7;



const int ALL_SIZE = 1100 * 2500;

int dp[1100][2500];



i32 main() {
	int n, m;
	cin >> n >> m;
	if (m == 1) {
		if (n % 2 == 0) {
			cout << 1 << endl;
		} else {
			cout << 0 << endl;
		}
		return 0;
	}
	if (n == 1) {
		if (m % 2 == 0) {
			cout << 1 << endl;
		} else {
			cout << 0 << endl;
		}
		return 0;
	}

	memset(dp, -1, sizeof(dp));

	function<void(int, int, int, vector<int>&)> gen;
	gen = [&](int j, int mask, int next_mask, vector<int>& list_mask) -> void {
		if (j == n) {
			list_mask.push_back(next_mask);
			return;
		}

		if (j + 1 < n && ((1 << j & mask) == 0 && (1 << (j + 1) & mask) == 0)) {
			gen(j + 2, mask, next_mask, list_mask);
		}

		if (0 == ((1 << j) & mask)) {
			gen(j  + 1, mask, next_mask + (1 << j), list_mask);
		}

		if (0 != ((1 << j) & mask)) {
			gen(j + 1, mask, next_mask, list_mask);
		}


	};
	
	function<int(int,int)> dfs;
	dfs = [&](int i, int mask) -> int {
		if (i == m) {
			if (mask == 0) {
				return 1;
			}
			return 0;
		}

		if (dp[i][mask] != -1) {
			return dp[i][mask];
		}
		vector<int> next_states;
		gen(0, mask, 0, next_states);
		int ans = 0;
		for (int next: next_states) {
			ans += dfs(i + 1, next);
			ans %= MOD;
		}
		dp[i][mask] = ans;
		return ans;
	};
	cout << dfs(0,0) << endl;

}
