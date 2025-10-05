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
	if (n == 1) {
		cout << 2 << endl;
		return;
	}
	if (n == 2) {
		cout << 1 << endl;
		return;
	}
	vector<int> dp(n);
	int pos = MAX_INT;
	for (int i = 0; i < n - 1; i++) {
		if (a[i] < a[i + 1]) {
			dp[i] = -1;
			pos = min(pos, i);
		} else if (a[i] > a[i + 1]) {
			dp[i] = 1;
			pos = min(pos, i);
		}
	}
	if (pos == MAX_INT) {
		if (n % 2 == 0) {
			int value = a.front();
			if (value == n / 2 || value == n / 2 + 1) {
				cout << 1 << endl;
			} else {
				cout << 0 << endl;
			}
			return;
		} else {
			int value = a.front();
			if (value == n / 2 + 1) {
				cout << 2 << endl;
			} else {
				cout << 0 << endl;
			}
			return;
		}
	}
	bool okay = true;
	for (int i = pos - 1; i >= 0; i--) { dp[i] = -dp[i + 1]; }
	for (int i = pos + 1; i < n; i++) {
		int calc;
		if (a[i] == a[i - 1]) {
			calc = -dp[i - 1];
		} else if (a[i - 1] < a[i]) {
			calc = -1;
		} else {
			calc = 1;
		}

		if (dp[i] == 0) {
			dp[i] = calc;

		} else {
			if (dp[i] != calc) { okay = false; }
		}
	}

	if (!okay) {
		cout << 0 << endl;
		return;
	}

	int left = 0;
	int right = 0;
	for (int i = 1; i < n; i++) { right += max(0LL, dp[i]); }
	vector<int> builded(n);
	builded[0] = right + 1;
	for (int i = 1; i < n; i++) {
		if (dp[i - 1] == -1) { left++; }
		if (dp[i] == 1) { right--; }
		builded[i] = left + right + 1;
	}

	for (int i = 0; i < n; i++) {
		if (builded[i] != a[i]) { okay = false; }
	}
	if (okay) {
		cout << 1 << endl;
	} else {
		cout << 0 << endl;
	}
}
