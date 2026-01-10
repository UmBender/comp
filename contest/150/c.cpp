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
	int n, w;
	cin >> n >> w;
	int c[n];
	for (int i = 0; i < n; i++) { cin >> c[i]; }
	int mod = 2 * w;
	vector<int> delta(mod + 1);
	for (int i = 0; i < n; i++) {
		int l = (-(i + 1)) % mod;
		if (l < 0) { l += mod; }

		int r = (l + w - 1) % mod;
		int cost = c[i];

		if (l <= r) {
			delta[l] += cost;
			delta[r + 1] -= cost;
		} else {
			delta[l] += cost;
			delta[mod] -= cost;
			delta[0] += cost;
			delta[r + 1] -= cost;
		}
	}

	int mmin = -1;
	int curr = 0;

	for (int i = 0; i < mod; i++) {
		curr += delta[i];
		if(mmin == -1 || curr < mmin) {
			mmin = curr;
		}
	}

	cout << mmin << endl;
}
