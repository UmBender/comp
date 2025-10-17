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
	if (n == 2) {
		cout << -1 << endl;
		return;
	}
	if (n == 3) {
		cout << 1 << " " << 3 << endl;
		cout << 2 << " " << 3 << endl;
		return;
	}
	int mmin = ((n + 2) * (n - 1)) / 2;
	int p = 1;
	while (p * p < mmin) { p++; }
	int pot = p * p;
	if (pot == mmin) {
		for (int i = 2; i <= n; i++) { cout << 1 << " " << i << endl; }
		return;
	}

	for (int node = 2; node <= n; node++) {
		int delta = (pot - mmin) + node;
		if (delta % node == 0 && delta / node <= n && delta / node != node) {
			int acc = 0;
			for (auto adj = 2; adj <= n; adj++) {
				if (adj == node) { continue; }
				cout << adj << " " << 1 << endl;
				acc += adj;
			}
			acc += delta;
			cout << node << " " << delta / node << endl;
			return;
		}
	}
	for (int puts = 2; puts < n; puts++) {
		mmin = (((n + 1) * n) / 2 - puts) * puts;
		while (p * p < mmin) { p++; }
		pot = p * p;

		if (pot == mmin) {
			for (int i = 1; i < puts; i++) { cout << puts << " " << i << endl; }
			for (int i = puts + 1; i <= n; i++) {
				cout << puts << " " << i << endl;
			}
			return;
		}
		for (int node = puts + 1; node <= n; node++) {
			if (node == puts) { continue; }
			int delta = (pot - mmin) + node * puts;
			if (delta % node == 0 && delta / node <= n &&
			    delta / node != node) {
				int acc = 0;
				for (auto adj = 1; adj <= n; adj++) {
					if (adj == node) { continue; }
					if (adj == puts) { continue; }
					cout << adj << " " << puts << endl;
					acc += adj * puts;
				}
				cout << node << " " << delta / node << endl;
				acc +=  delta;
				return;
			}
		}
	}
}
