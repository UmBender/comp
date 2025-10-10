#include <bits/stdc++.h>
using namespace std;
#define int int64_t

void solution();
signed main() {
	solution();
	return 0;
}

struct BIT {
	vector<int> base;
	vector<int> tree;
	int n;
	BIT(vector<int> bbase)
	    : base(bbase.size()), tree(bbase.size() + 1), n(bbase.size()) {
		for (int i = 0; i < n; i++) { update(i, bbase[i]); }
	}
	void update(int pos, int value) {
		int delta = value - base[pos];
		base[pos] = value;
		for (pos++; pos <= n; pos += (-pos & pos)) { tree[pos] += delta; }
	}
	inline int query(int left, int right) {
		return query(right) - query(left - 1);
	}
	int query(int pos) {
		int acc = 0;
		for (pos++; pos > 0; pos -= (-pos & pos)) { acc += tree[pos]; }
		return acc;
	}
};

void solution() {
	int n, q;
	cin >> n >> q;
	vector<vector<int>> adj(n);
	vector<int> base(n);
	for (int i = 0; i < n; i++) { cin >> base[i]; }

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> dfs_arr;
	vector<int> t_begin(n);
	vector<int> t_end(n);
	function<void(int, int)> dfs;
	dfs = [&](int actual, int last) {
		dfs_arr.push_back(base[actual]);
		t_begin[actual] = dfs_arr.size() - 1;
		for (auto next : adj[actual]) {
			if (next == last) { continue; }
			dfs(next, actual);
		}
		dfs_arr.push_back(-base[actual]);
		t_end[actual] = dfs_arr.size() - 1;
	};
	dfs(0,0);
	BIT bit(dfs_arr);
	for (int qq = 0; qq < q; qq++) {
		int opt;
		cin >> opt;
		if (opt == 1) {
			int s, x;
			cin >> s >> x;
			s--;
			bit.update(t_begin[s], x);
			bit.update(t_end[s], -x);
		}else{
			int s;
			cin >> s;
			s--;
			cout << bit.query(t_begin[0], t_begin[s]) << endl;
		}
	}
}
