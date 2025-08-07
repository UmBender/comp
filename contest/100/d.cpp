// clang-format off
#include <atcoder/modint>
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
using mint = atcoder::modint;
// clang-format on

void solution() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n);
	for (int k = 0; k < m; k++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if (m != n - 1) {
		cout << 0 << endl;
		return;
	}
	int root = 0;
	for (int i = 0; i < n; i++) {
		if (adj[i].size() > 1) { root = i; }
	}
	queue<pair<int, int>> q;
	q.push({-1, root});
	vector<bool> acessed(n);
	acessed[root] = true;
	bool is_tree = true;
	vector<int> parents(n, -1);
	vector<vector<int>> childs(n);
	vector<int> gram(n);
	vector<mint> counter(n);
	parents[root] = -1;
	while (!q.empty() && is_tree) {
		auto [last, actual] = q.front();
		q.pop();
		for (int next : adj[actual]) {
			if (next == last) { continue; }
			if (acessed[next]) {
				is_tree = false;
				break;
			}
			parents[next] = actual;
			childs[actual].push_back(next);
			q.push({actual, next});
			if (last != -1) { acessed[next] = true; }
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j : childs[i]) {
			if (childs[j].size() != 0) { gram[i]++; }
		}
	}
	int two_gram = 0;

	for (int i = 0; i < n; i++) {
		if (gram[i] > 2) { is_tree = false; }
		if (gram[i] == 2 && i != root) { two_gram++; }
	}
	if (two_gram != 0) {
		cout << 0 << endl;
		return;
	}
	if (!is_tree) {
		cout << 0 << endl;
		return;
	}
	bool height = false;
	function<mint(int)> dfs;
	dfs = [&](int node) -> mint {
		if (childs[node].size() == 0) { return 1; }
		mint actual = 1;
		int leaf = 0;
		vector<mint> non_leaf;
		for (int next_node : childs[node]) {
			if (childs[next_node].size() == 0) {
				leaf++;
			} else {
				mint result = dfs(next_node);
				non_leaf.push_back(result);
			}
		}
		for (int i = 1; i <= leaf; i++) { actual *= i; }
		if (non_leaf.empty()) { return actual; }
		for (mint i : non_leaf) {
			actual *= i;
			height = true;
		}
		return actual;
	};

	mint result = dfs(root) * 2;
	if (height) { result *= 2; }

	cout << result.val() << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	atcoder::modint::set_mod(1E9 + 7);
	int t;
	cin >> t;
	while (t--) solution();

	return 0;
}
