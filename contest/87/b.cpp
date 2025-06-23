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

void solution() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll k = 0; k < n; k++) { cin >> a[k]; }
	ll minimal = MAX_INT;
	for (ll k = 0; k < n - 1; k++) {
		if (abs(a[k] - a[k + 1]) <= 1) { minimal = 0; }
	}
	for (ll k = 1; k < n - 1; k++) {
		if (a[k - 1] < a[k] && a[k] > a[k + 1]) { minimal = min(1LL, minimal); }
		if (a[k - 1] > a[k] && a[k] < a[k + 1]) { minimal = min(1LL, minimal); }
	}

	if (minimal == MAX_INT) { minimal = -1; }
	cout << minimal << endl;
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
