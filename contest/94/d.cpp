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
	int n, k;
	cin >> n >> k;
	vector<tuple<int, int, int>> cassinos(n);
	for (auto &[l, real, r] : cassinos) { cin >> l >> r >> real; }
	sort(cassinos.begin(), cassinos.end());
	set<int> old_possible;
	old_possible.insert(k);
	auto check = [&](int l, int r) -> bool {
		auto it = old_possible.lower_bound(l);
		return (it != old_possible.end() && *it <= r);
	};
	for (int i = 0; i < n; i++) {
		auto [l, real, r] = cassinos[i];
		if (check(l, r)) { old_possible.insert(real); }
	}
	cout << *old_possible.rbegin() << endl;
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
