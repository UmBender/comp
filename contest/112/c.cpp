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
	map<pair<int, int>, pair<int, int>> costs;

	vector<vector<int>> adj(n);
	vector<vector<int>> radj(n);
	vector<int> counter(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v, x, y;
		cin >> u >> v >> x >> y;
		u--, v--;
		costs[{u, v}] = {x, y};
		adj[u].push_back(v);
		radj[v].push_back(u);
		counter[u]++;
		counter[v]++;
	}
	vector<map<int, int>> nadj(n);
	vector<pair<int, int>> greter(n);
	vector<pair<int, int>> lower(n);
	for (int i = 0; i < n; i++) {
		for (auto next : adj[i]) {
			auto [x, y] = costs[{i, next}];
			if (x > y) {
				nadj[i][next] = -1;
				nadj[next][i] = 1;

			} else {
				nadj[i][next] = 1;
				nadj[next][i] = -1;
			}
		}
	}
	vector<int> p(n);
	set<int> candidates;
	map<int, int> bigger;
	for (int i = 0; i < n; i++) {
		for (auto [next, value] : nadj[i]) {
			if (value == -1) { bigger[i]++; }
		}
	}
	for (int i = 0; i < n; i++) {
		bool okay = true;
		for (auto [next, value] : nadj[i]) {
			if (value == -1) { okay = false; }
		}
		if (okay) { candidates.insert(i); }
	}
	set<int> used;
	for (int i = 0; i < n; i++) { used.insert(i); }
	for (int i = 1; i <= n; i++) {
		int actual_node = *candidates.begin();
		for (auto [next, val] : nadj[actual_node]) {
			if (val == 1) {
				bigger[next]--;
				if (bigger[next] == 0) { candidates.insert(next); }
			}
		}
		candidates.erase(actual_node);
		p[actual_node] = i;
	}
	for (int i = 0; i < n; i++) { cout << p[i] << " \n"[i == n - 1]; }
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
