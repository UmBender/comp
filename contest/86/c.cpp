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
	int n, m;
	cin >> n >> m;
	if (m < n || m > ((n + 1) * n) / 2) {
		cout << -1 << endl;
		return;
	}
	vector<ll> elements;
	set<int> used;
	ll actual_m = 0;
	for (ll k = n; k > 0; k--) {
		if (k + actual_m + (n - (used.size()+1)) <= m) {
			actual_m += k;
			elements.push_back(k);
			used.insert(k);
		}
	}
	for (ll k = 1; k <= n; k++) {
		if (!used.count(k)) {
			elements.push_back(k);
			used.insert(k);
		}
	}
	cout << elements.front() << endl;
	for (int k = 0; k < n - 1; k++) {
		cout << elements[k] << " " << elements[k + 1] << endl;
	}
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
