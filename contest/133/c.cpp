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
	int a[2][n + 1];
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= n; j++) { cin >> a[i][j]; }
	}

	vector<int> pref_min(2 * n + 1), pref_max(2 * n + 1);
	vector<int> suff_min(2 * n + 1), suff_max(2 * n + 1);
	pref_min[0] = INT_MAX, pref_max[0] = INT_MIN;
	for (int i = 1; i <= n; i++) {
		pref_min[i] = min(pref_min[i - 1], a[0][i]);
		pref_max[i] = max(pref_max[i - 1], a[0][i]);
	}
	suff_min[n + 1] = INT_MAX, suff_max[n + 1] = INT_MIN;
	for (int i = n; i >= 1; i--) {
		suff_min[i] = min(suff_min[i + 1], a[1][i]);
		suff_max[i] = max(suff_max[i + 1], a[1][i]);
	}
	int m = 2 * n;
	vector<vector<int>> conn(m + 2);
	for (int k = 1; k <= n; k++) {
		int lk = min(pref_min[k], suff_min[k]);
		int rk = max(pref_max[k], suff_max[k]);
		conn[lk].push_back(rk);
	}

	multiset<int> ms;
	ll ans = 0;
	for (int l = m; l >= 1; --l) {
		for (int r : conn[l]) ms.insert(r);
		if (!ms.empty()) {
			int mmin = *ms.begin();
			ans += m - mmin + 1;
		}
	}

	cout << ans << '\n';
}
