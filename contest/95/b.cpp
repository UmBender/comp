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
	int n;
	cin >> n;
	vector<tuple<int, int, int, int>> list(n);
	for (auto &[a, b, c, d] : list) { cin >> a >> b >> c >> d; }
	vector<pair<int, int>> deltas(n);
	for (int i = 0; i < n; i++) {
		deltas[i].first = get<2>(list[i]) - get<0>(list[i]);
		deltas[i].second = get<3>(list[i]) - get<1>(list[i]);
	}
	int cost_zeros = 0;
	for (auto [first, _] : deltas) { cost_zeros += max(first, 0LL); }
	int cost_ones = 0;
	for (int i = 0; i < n; i++) {
		if (deltas[i].second >= 0) { continue; }
		cost_ones += abs(deltas[i].second);
		int moving_cost = min(get<0>(list[i]), get<2>(list[i]));
		cost_ones += moving_cost;
	}
	cout << cost_zeros + cost_ones << endl;
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
