// clang-format off
//#include <atcoder/all>
#include <bits/stdc++.h>
#include <functional>
#include <numeric>
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
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (auto &i : a) { cin >> i; }
	vector<map<int, int>> adj(n);
	vector<int> edges;
	for (int i = 0; i < n - 1; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		u--, v--;
		adj[u][v] = c;
		adj[v][u] = c;
		edges.push_back(c);
	}
	vector<int> parents(n);
	vector<set<int>> child(n);
	vector<map<int, int>> colors_costs(n);
	vector<bool> acessed(n);
	function<void(int)> dfs;
	int acc = 0;
	dfs = [&](int actual_node) {
		acessed[actual_node] = true;
		for (auto &[i, j] : adj[actual_node]) {
			if (!acessed[i]) {
				parents[i] = actual_node;
				child[actual_node].insert(i);
				colors_costs[actual_node][a[i]] += j;
				dfs(i);
			}
		}
		acc += colors_costs[actual_node][a[actual_node]];
	};
	dfs(0);
	parents[0] = -1;
	int sum = reduce(edges.begin(), edges.end(), 0LL);
	while (q--) {
		int v, x;
		cin >> v >> x;
		v--;
		if (v == 0) {
			acc -= colors_costs[v][a[v]];
			acc += colors_costs[v][x];
			a[v] = x;
		} else {
			int parent = parents[v];
			acc -= colors_costs[v][a[v]];
			acc += colors_costs[v][x];
			acc -= colors_costs[parent][a[parent]];
			colors_costs[parent][a[v]] -= adj[parent][v];
			colors_costs[parent][x] += adj[parent][v];
			acc += colors_costs[parent][a[parent]];
			a[v] = x;
		}
		cout << sum - acc << endl;
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
