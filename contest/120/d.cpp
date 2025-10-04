// clang-format off
//#include <atcoder/all>
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
	while(t--)
		solution();
	// clang-format on

	return 0;
}

void solution() {
	int n;
	cin >> n;
	vector<int> a(n);
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) { a[i] = s[i] == '1'; }
	int minimal = MAX_INT;
	auto calc = [&]() {
		vector<int> dp[2];
		dp[0] = vector<int>(n + 1);
		dp[1] = vector<int>(n + 1);
		int acc = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == 0) {
				dp[0][i + 1] = acc + 1 + dp[0][i];
				acc = 0;
			} else {
				dp[0][i + 1] = dp[0][i];
				acc += 2;
			}
		}

		acc = 0;
		for (int i = n; i > 0; i--) {
			if (a[i - 1] == 0) {
				dp[1][i - 1] = acc + 1 + dp[1][i];
				acc = 0;
			} else {
				dp[1][i - 1] = dp[1][i];
				acc += 2;
			}
		}

		for (int i = 0; i < n; i++) {
			minimal = min(minimal, dp[0][i] + dp[1][i]);
		}
	};
	calc();
	for (int i = 0; i < n; i++) { a[i] = s[i] == '0'; }
	calc();
	cout << minimal << endl;
}
