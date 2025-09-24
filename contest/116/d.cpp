// clang-format off
#include <atcoder/modint>
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
using mint = atcoder::modint;
// clang-format on

void solution();
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	atcoder::modint::set_mod(998244353);
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
	if (n == 2) {
		if (a[0] == 2 && a[1] == 0) {
			cout << 1 << endl;
		} else {
			cout << 0 << endl;
		}
		return;
	}
	int counter = 0;
	for (int i = 0; i < n; i++) { counter += a[i]; }
	if (counter != n) {
		cout << 0 << endl;
		return;
	}
	bool possible = true;
	for (int i = n - 1; i >= (n + 1) / 2; i--) {
		if (a[i] != 0) {
			possible = false;
			break;
		}
	}
	for (int i = 0; i < (n + 1) / 2; i++) {
		int width = n - 2 * i;
		if (a[i] > width) {
			possible = false;
			break;
		}
	}
	if (!possible) {
		cout << 0 << endl;
		return;
	}
	for (int i = n - 1; i >= 0; i--) {
		int line_size = n - 2 * i;
		if (line_size <= 0 && a[i] != 0) {
			cout << 0 << endl;
			return;
		}
		if (line_size <= 0) { a.pop_back(); }
	}

	ranges::reverse(a);
	int used = 0;
	int size = n;
	n = a.size();
	vector<int> line_size(n);
	line_size[0] = size;
	for (int i = 1; i < n; i++) { line_size[i] = line_size[i - 1] - 2; }
	ranges::reverse(line_size);

	vector<mint> dp(n);
	vector<mint> fact(2 * (n + 1));
	fact[0] = 1;
	for (int i = 1; i < fact.size(); i++) { fact[i] = fact[i - 1] * i; }
	for (int i = 0; i < n; i++) {
		int space = line_size[i] - used;
		int free_space = space - a[i];
		mint possi = fact[space];
		if (free_space < 0) {
			dp[i] = 0;
			break;
		} else {
			possi /= fact[free_space];
			possi /= fact[a[i]];
			dp[i] = possi;
			used += a[i];
		}
	}
	mint acc = 1;
	for (int i = 0; i < n; i++) { acc *= dp[i]; }
	cout << acc.val() << endl;
}
