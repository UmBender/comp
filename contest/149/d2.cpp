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
    while (t--) { 
        solution();
	}
	// clang-format on

	return 0;
}

struct Node {
	int id;
	int nuse;
};

void solution() {
	int n;
	cin >> n;
	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> height(n + 1, -1);
	vector<int> parent(n + 1, 0);
	vector<vector<int>> height_child(n + 1);
	vector<int> childrens(n + 1, 0);

	queue<int> q;
	q.push(1);
	parent[1] = 0;
	height[1] = 0;
	height_child[0].push_back(1);
	vector<bool> visited(n + 1);
	visited[1] = true;

	int max_height = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v : adj[u]) {
			if (v == parent[u]) { continue; }
			visited[v] = true;
			parent[v] = u;
			height[v] = height[u] + 1;
			height_child[height[v]].push_back(v);
			childrens[u]++;
			max_height = max(max_height, height[v]);
			q.push(v);
		}
	}

	int mmax = 0;
	for (int i = 0; i <= max_height; i++) {
		mmax = max(mmax, (int)height_child[i].size());
	}
	for (int i = 1; i <= n; i++) { mmax = max(mmax, childrens[i] + 1); }
	vector<vector<int>> result_sets(mmax + 1);
	vector<int> node_colors(n + 1, 0);

	node_colors[1] = 1;
	result_sets[1].push_back(1);


	vector<int8_t> bad_shift(mmax);
	for (int d = 1; d <= max_height; d++) {
		vector<Node> curr_nodes;
		vector<int8_t> removed;

		for (int u : height_child[d]) {
			curr_nodes.push_back({u, node_colors[parent[u]]});
		}


		sort(curr_nodes.begin(), curr_nodes.end(),
		     [](const Node &a, const Node &b) { return a.nuse < b.nuse; });

		fill(bad_shift.begin(), bad_shift.end(), 0);
		for (int i = 0; i < curr_nodes.size(); i++) {
			int f = curr_nodes[i].nuse;
			int s = (f - 1 - i) % mmax;
			if (s < 0) { s += mmax; }
			bad_shift[s] = true;
		}

		int best_shift = -1;
		for (int s = 0; s < bad_shift.size(); s++) {
			if (!bad_shift[s]) {
				best_shift = s;
				break;
			}
		}

		for (int i = 0; i < curr_nodes.size(); i++) {
			if (curr_nodes[i].id != -1) {
				int ac_color = ((i + best_shift) % mmax) + 1;
				node_colors[curr_nodes[i].id] = ac_color;
				result_sets[ac_color].push_back(curr_nodes[i].id);
			}
		}
	}

	cout << mmax << endl;

	for (int c = 1; c <= mmax; c++) {
		cout << result_sets[c].size();
		for (int u : result_sets[c]) { cout << " " << u; }
		cout << endl;
	}
}
