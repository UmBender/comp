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
	solution();
	// clang-format on

	return 0;
}

void solution() {
	int n, m;
	cin >> n >> m;
	vector<string> grid(n);
	for (auto &i : grid) { cin >> i; }
	auto build = [&](int i, int j, int delta) -> vector<string> {
		vector<string> g(delta);
		for (int ii = 0; ii < delta; ii++) {
			for (int jj = 0; jj < delta; jj++) {
				g[ii].push_back(grid[i + ii][j + jj]);
			}
		}
		return g;
	};
	set<vector<string>> counter;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (max(i, j) + m <= n) {
				auto holder = build(i, j, m);
				if (!counter.count(holder)) { counter.insert(holder); }
			}
		}
	}
	cout << counter.size() << endl;
}
