#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using i32 = int;
using i64 = long long;
using i128 = __int128;
using VI = vector<i32>;
using VVI = vector<VI>;
using PII = pair<i32, i32>;
using VII = vector<PII>;
using VVII = vector<VII>;

// clang-format off
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

int op(int a, int b) { return max(a, b); }
int e() { return -1; }

i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, d;
	cin >> n >> d;
	vector<int> a(n);
	vector<int> vals(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		vals[i] = a[i];
	}
	sort(vals.begin(), vals.end());
	vals.erase(unique(vals.begin(), vals.end()), vals.end());
	segtree<int, op, e> st(vals.size());
	int ans = 0;
	int l = 0;
	for (int r = 0; r < n; r++) {
		int v = a[r];
		int mn = v - d + 1;
		int mx = v + d - 1;
		int i_l = lower_bound(vals.begin(), vals.end(), mn) - vals.begin();
		int i_r = upper_bound(vals.begin(), vals.end(), mx) - vals.begin();
		int hit = st.prod(i_l, i_r);
		if (hit != -1) { l = max(l, hit + 1); }
		ans += (r - l + 1);
		int i = lower_bound(vals.begin(), vals.end(), v) - vals.begin();
		st.set(i, r);
	}
	cout << ans << endl;
	return 0;
}
