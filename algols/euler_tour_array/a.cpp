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
struct BIT {
	vector<int> base;
	vector<int> tree;
	int size;
	BIT(int size) : base(size), tree(size + 1), size(size) {}
	BIT(vector<int> &base)
	    : base(base.size()), tree(base.size() + 1), size(base.size()) {}
	void update(int pos, int value) {
		int delta = value - base[pos];
		pos++;
		for (; pos < tree.size(); pos += (pos & -pos)) { tree[pos] += delta; }
	}
	int query(int right) {
		int acc = 0;
		right++;
		for (; right > 0; right -= (right & -right)) { acc += tree[right]; }

		return acc;
	}
	int query(int left, int right) { return query(right) - query(left - 1); }
};

struct EulerTourArray {
	BIT bit;
	vector<int> begin;
	vector<int> end;
	vector<vector<int>> adj;
	int root;
	EulerTourArray(vector<vector<int>> &adj, vector<int> &values, int root)
	    : bit(2 * adj.size()), begin(adj.size()), end(adj.size()), adj(adj),
	      root(root) {
		function<void(int, int)> dfs;
		vector<int> construction;
		dfs = [&](int actual, int last) {
			construction.push_back(values[actual]);
			begin[actual] = construction.size() - 1;
			for (auto next : adj[actual]) {
				if (next == last) { continue; }
				dfs(next, actual);
			}

			construction.push_back(-values[actual]);
			end[actual] = construction.size() - 1;
		};
		dfs(root, root);
		for (int i = 0; i < 2 * adj.size(); i++) {
			bit.update(i, construction[i]);
		}
	}

	EulerTourArray(vector<vector<int>> &adj, vector<int> &values)
	    : EulerTourArray(adj, values, 0) {}

	void update(int node, int value) {
		int old_value = bit.query(begin[node], begin[node]);
		bit.update(begin[node], -old_value);
		bit.update(end[node], old_value);
		bit.update(begin[node], value);
		bit.update(end[node], value);
	}

	int query(int begin_node, int end_node) {
		return bit.query(begin[begin_node], end[end_node] - 1);
	}
};

void solution() {
	int n, q;
	cin >> n >> q;
	vector<vector<int>> adj(n);
	vector<int> values(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (auto &i : values) { cin >> i; }
	EulerTourArray eta(adj, values);
	while (q--) {
		int opt;
		cin >> opt;
		if (opt == 1) {
			int bn, en;
			cin >> bn >> en;
			bn--, en--;
			cout << eta.query(bn, en) << endl;
		} else {
			int node, value;
			cin >> node >> value;
			node--;
			eta.update(node, value);
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	solution();

	return 0;
}
