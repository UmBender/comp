#include <vector>
#include <iostream>
#include <array>
#include <map>
#include <utility>
#include <functional>
#include <numeric>
#include <set>
#include <format>


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

const int MAX_SIZE = 1e5 + 100;
const int MAX_VALUE = 1e9 + 100;
array<int, MAX_SIZE> h;
array<int, MAX_SIZE> dp;


i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	fill(dp.begin(), dp.end(), MAX_VALUE);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int delta = -1; delta >= -2; delta--) {
			if (i + delta < 0) {
				break;
			}
			dp[i] = min(dp[i + delta] + abs(h[i] - h[i + delta]), dp[i]);
		}
	}
	cout << dp[n - 1] << endl;


	
	return 0;
}


