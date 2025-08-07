// clang-format off
//#include <atcoder/all>
#include <bits/stdc++.h>
#include <cassert>
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
#define makeconst(value) []( return (value);)
using ll = long long;
using ld = long double;
#define int ll
using i64 = long long; using u64 = unsigned long long; using f32 = float; using f64 = double; using f128  = long double;
//using mint = atcoder::modint;
// clang-format on

void solution() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> ab(n);
	for (auto &i : ab) { cin >> i.first; }
	for (auto &i : ab) { cin >> i.second; }
	int v = 0;
	for (int i = 0; i < n; i++) { v += abs(ab[i].first - ab[i].second); }
	int nv = 0;
	for (int i = 0; i < n; i++) {
		if (ab[i].first < ab[i].second) { ab[i] = {ab[i].second, ab[i].first}; }
	}
	sort(ab.begin(), ab.end());
	for (int i = 0; i < n; i++) { nv += abs(ab[i].first - ab[i].second); }
	set<int> numbers;
	numbers.insert(ab.back().second);
	int minimal = MAX_INT;
	for (int i = n - 2; i >= 0; i--) {
		auto [big, small] = ab[i];
		auto lowest_value = *numbers.begin();
		minimal = min(minimal, max(0LL, 2 * (lowest_value - big)));
		if (!numbers.count(small)) { numbers.insert(small); }
	}
	cout << v + minimal << endl;
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
