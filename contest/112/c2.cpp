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
#define makeconst(value) []( return (value);)
using ll = long long;
using ld = long double;
#define int ll
using i64 = long long; using u64 = unsigned long long; using f32 = float; using f64 = double; using f128  = long double;
//using mint = atcoder::modint;
// clang-format on

void solution() {
	int n;
	cin >> n;
	vector<vector<pair<int, bool>>> adj(n + 1);
	for (int i = 1; i < n; i++) {
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		if (x > y) {
			adj[a].emplace_back(b, false);
			adj[b].emplace_back(a, true);
		} else {
			adj[a].emplace_back(b, true);
			adj[b].emplace_back(a, false);
		}
	}
	vector<int> perm(n + 1);
	int l = 1, r = n;
	auto dfs = [&](auto &&self, int x, int par = -1) -> void {
		for (auto [y, b]: adj[x]) {
			if (y == par) {
				continue;
			}
			self(self, y, x);
			if (b) {
				perm[y] = r--;
			} else {
				perm[y] = l++;
			}
		}
	};
	dfs(dfs, 1);
	perm[1] = l;
	for (int i = 1; i <= n; i++) {
		cout << perm[i] << " ";
	}
	cout << endl;
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
