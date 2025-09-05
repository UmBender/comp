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
//

struct SegTree {
	vector<int> tree;
	int size;
	SegTree() : tree(0), size(0) {}
	SegTree(int size) : tree(size * 4), size(size) {}
	SegTree(vector<int> &array) : tree(array.size() * 4), size(array.size()) {
		build(1, 0, size - 1, array);
	}

	void build(int p, int tl, int tr, vector<int> &array) {
		if (tl == tr) {
			tree[p] = array[tl];
			return;
		}
		int tm = (tl + tr) / 2;
		build(2 * p, tl, tm, array);
		build(2 * p + 1, tm + 1, tr, array);
		tree[p] = tree[2 * p] + tree[2 * p + 1];
	}

	void update(int p, int tl, int tr, int pos, int value) {
		if (tl == tr) {
			tree[p] = value;
			return;
		}
		int tm = (tl + tr) / 2;
		if (pos <= tm) {
			update(p * 2, tl, tm, pos, value);
		} else {
			update(p * 2 + 1, tm + 1, tr, pos, value);
		}
		tree[p] = tree[2 * p] + tree[2 * p + 1];
	}

	inline void update(int pos, int value) {
		update(1, 0, size - 1, pos, value);
	}

	int query(int pos, int tl, int tr, int left, int right) {
		if (tl == left && tr == right) { return tree[pos]; }
		if (tl > right || tr < left) { return 0; }
		if (left > right) { return 0; }
		int tm = (tl + tr) / 2;
		int l = query(pos * 2, tl, tm, left, min(tm, right));
		int r = query(pos * 2 + 1, tm + 1, tr, max(tm + 1, left), right);
		return l + r;
	}

	inline int query(int left, int right) {
		return query(1, 0, size - 1, left, right);
	}
};

struct DFSArray {
	SegTree seg_tree;
	vector<int> rev;
	vector<int> dfs_array;
	vector<int> subtree_size;

	DFSArray(vector<vector<int>> &adj, int first)
	    : seg_tree(adj.size()), rev(adj.size()), subtree_size(adj.size()) {
		function<void(int, int)> dfs;
		dfs_array.push_back(first);
		vector<int> associativ;
		associativ.push_back(first);
		dfs = [&](int actual, int last) {
			for (int next : adj[actual]) {
				if (next == last) { continue; }
				dfs_array.push_back(0);
				associativ.push_back(next);
				dfs(next, actual);
				subtree_size[actual] += subtree_size[next];
			}
			subtree_size[actual]++;
		};
		dfs(first, first);
		for (int i = 0; i < adj.size(); i++) { rev[associativ[i]] = i; }
	}
	DFSArray(vector<vector<int>> &adj) { DFSArray(adj, 0); }

	void update(int node, int value) { seg_tree.update(rev[node], value); }

	int query(int node) {
		return seg_tree.query(rev[node],
		                      rev[node] + subtree_size[node] - 1);
	}
};

vector<vector<int>> adj;

void solution() {
	int n, q;
	cin >> n >> q;
	adj = vector<vector<int>>(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	DFSArray dfsarray(adj, 9);

	for (int i = 0; i < n; i++) {
		int v;
		cin >> v;
		dfsarray.update(i, v);
	}

	while (q--) {
		int opt;
		cin >> opt;
		if (opt == 1) {
			int node;
			cin >> node;
			node--;
			cout << dfsarray.query(node) << endl;
		} else {
			int node, value;
			cin >> node >> value;
			node--;
			dfsarray.update(node, value);
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
