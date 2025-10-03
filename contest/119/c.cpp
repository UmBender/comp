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
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (auto &i : a) { cin >> i; }
	vector<int> pref[2];
	pref[0] = vector<int>(n + 1);
	pref[1] = vector<int>(n + 1);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			pref[i][j + 1] = pref[i][j] + (a[j] == i);
		}
	}

	vector<pair<int, int>> lr(q);
	for (auto &[l, r] : lr) {
		cin >> l >> r;
		l--, r--;
	}
	set<int> succ[2];
	for (int i = 0; i < n - 1; i++) {
		if (a[i] == a[i + 1]) { succ[a[i]].insert(i); }
	}
	for (auto [l, r] : lr) {
		if ((r - l + 1) % 3 != 0) {
			cout << -1 << endl;
			continue;
		}
		int ones = pref[1][r + 1] - pref[1][l];
		int zeros = pref[0][r + 1] - pref[0][l];
		if (0 != ones % 3 || 0 != zeros % 3) {
			cout << -1 << endl;
			continue;
		}
		auto zero_pos = succ[0].lower_bound(l);
		auto one_pos = succ[1].lower_bound(l);
		bool okay = false;
		if (zero_pos != succ[0].end()) {
			if (*zero_pos <= r - 1) { okay = true; }
		}
		if (one_pos != succ[1].end()) {
			if (*one_pos <= r - 1) { okay = true; }
		}
		int counter = 0;
		if (!okay) {
			counter = 1 + (r - l + 1) / 3;
		} else {
			counter = (r - l + 1) / 3;
		}
		cout << counter << endl;
	}
}
