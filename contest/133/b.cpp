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
	vector<int> a(n);
	for (int i = 0; i < n; i++) { cin >> a[i]; }
	string x;
	cin >> x;
	vector<bool> xx(n);
	for (int i = 0; i < n; i++) { xx[i] = x[i] == '1'; }
	int max_pos = 0, min_pos = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == n) { max_pos = i; }
		if (a[i] == 1) { min_pos = i; }
	}
	if (xx[max_pos] || xx[min_pos]) {
		cout << -1 << endl;
		return;
	}
	{
		int counter{0};
		for (int i = 0; i < n; i++) { counter += xx[i]; }
		if (!counter) {
			cout << 0 << endl;

			return;
		}
	}
	if (xx[0] || xx[n - 1]) {
		cout << -1 << endl;
		return;
	}

	set<int> positions;
	for (int i = 0; i < n; i++) {
		if (xx[i]) { positions.insert(i); }
	}
	map<int, int> mp;
	for (int i = 0; i < n; i++) { mp[a[i]] = i; }
	vector<pair<int, int>> sol;
	sol.push_back({1, n});
	sol.push_back({min(1ll, mp[1] + 1), max(mp[1]+1, 1ll)});
	sol.push_back({min(n, mp[1]+1), max(n, mp[1]+1)});
	sol.push_back({min(n, mp[n]+1), max(n, mp[n])});
	sol.push_back({min(1ll, mp[n]+1), max(1ll, mp[n] + 1)});
	vector<pair<int, int>> real;
	for (auto [a, b] : sol) {
		if (a != b) { real.push_back({a, b}); }
	}
	mkunique(real);
	cout << real.size() << endl;
	for (auto [x, y] : real) { cout << x << " " << y << endl; }
}
