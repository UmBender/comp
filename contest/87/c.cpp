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
using ll = long long;
using ld = long double;
#define int ll
//using mint = atcoder::modint;
// clang-format on

template <typename T> void dbg_vec(vector<T> &a) {
	for (ll k = 0; k < static_cast<ll>(a.size()); k++) {
		cout << format("vec[{}] = {}", k + 1, a[k]) << endl;
	}
}

template <typename T> void dbg_vec(vector<T> &a, ll limit) {
	for (ll k = 0; k < static_cast<ll>(limit); k++) {
		cout << format("vec[{}] = {}", k + 1, a[k]) << endl;
	}
}

int lb(vector<int> &a, int maxx, int minimal) {
	int lbb = MAX_INT;
	int l = 0;
	int r = maxx;
	while (l <= r) {
		int m = l + (r - l) / 2;
		if (a[m] >= minimal) {
			lbb = min(lbb, m);
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	if (lbb == MAX_INT) { lbb = -1; }
	return lbb;
}
void solution() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (auto &i : a) { cin >> i; }
	vector<ll> dp(1E5 + 10);
	int counter = 0;
	vector<int> pref(dp.size() + 1);
	for (int i = 0; i < n; i++) { dp[a[i]]++; }
	for (int i = 0; i < dp.size(); i++) { pref[i + 1] = pref[i] + dp[i]; }
	for (int i = 2; i < n; i++) {
		int mmax = max(a[i] * 2, a.back());

		for (int j = i - 1; j >= 0; j--) {
			int minimal = (mmax + 1) - (a[i] + a[j]);
			int pos = lb(a, j - 1, minimal);
			if (pos != -1) { counter += (j - pos); }
		}
	}
	cout << counter << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	int t;
	cin >> t;
	while (t--) solution();

	return 0;
}
