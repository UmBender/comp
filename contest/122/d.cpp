// clang-format off
//#include <atcoder/all>
#include <algorithm>
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
#define makeconst(value) []() { return (value); }
using ll = long long;
using ld = long double;
#define int ll
using i64 = long long; using u64 = unsigned long long; using f32 = float; using f64 = double; using f128  = long double;
#define ssort(x) ranges::sort(x)
#define mkunique(x) ranges::sort(x), x.erase(unique(x.begin(), x.end()), x.end()), x.shrink_to_fit()
//using mint = atcoder::modint;
// clang-format on
void solution();

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	// clang-format off
	int t;
	cin >> t;
	while (t--) 
		solution();
	// clang-format on

	return 0;
}

void solution() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a) { cin >> i; }
	int mmin = MAX_INT;
	auto median = [](int a, int b, int c) -> int {
		vector<int> x = {a, b, c};
		ssort(x);
		return x[1];
	};
	auto check = [&median](int a, int b, int c) -> int {
		int m = median(a, b, c);
		int cost = abs(m - a) + abs(m - b) + abs(m - c);
		return cost;
	};
	auto calc_dp2 = [&n](vector<int> &a) -> vector<int> {
		vector<int> values;
		for (int i = 0; i < n - 1; i++) {
			values.push_back(abs(a[i] - a[i + 1]));
		}
		return values;
	};
	auto calc_dp3 = [&check](vector<int> &a) -> vector<int> {
		int n = a.size();
		vector<int> values;
		for (int i = 0; i < n - 2; i++) {
			values.push_back(check(a[i], a[i + 1], a[i + 2]));
		}
		return values;
	};

	auto exec_dp = [&](vector<int> a) -> int {
		vector<int> dp2 = calc_dp2(a), dp3 = calc_dp3(a);
		vector<int> dp(n + 1, MAX_INT);
		dp[0] = 0;
		for (int i = 0; i < n; i++) {
			if (i + 2 <= n) { dp[i + 2] = min(dp[i + 2], dp[i] + dp2[i]); }
			if (i + 3 <= n) { dp[i + 3] = min(dp[i + 3], dp[i] + dp3[i]); }
		}
		return dp[n];

	};
	for (int i = 0; i < 4; i++) {
		mmin = min(exec_dp(a),mmin);
		vector<int> holder(n);
		for (int i = 0; i < n; i++) { holder[(i + 1) % n] = a[i]; }
		a = holder;
	}
	cout << mmin << endl;
}
