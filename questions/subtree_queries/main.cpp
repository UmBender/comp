#include <bits/stdc++.h>
using namespace std;

#define int int64_t
int n, q;
vector<vector<int>> adj;
vector<int> base;
vector<int> tbegin;
vector<int> tend;
vector<int> dfs_arr;

struct BIT {
	vector<int> base;
	vector<int> tree;
	int size;
	BIT(vector<int> ref)
	    : base(ref.size()), tree(ref.size() + 1), size(ref.size()) {
		for (int i = 0; i < n; i++) { update(i, ref[i]); }
	}

	void update(int pos, int value) {
		int delta = value - base[pos];
		base[pos] = value;
		for (pos++; pos <= size; pos += (-pos & pos)) { tree[pos] += delta; }
	}
	int query(int left, int right) { return query(right) - query(left - 1); }
	inline int query(int right) {
		int acc = 0;
		for (right++; right > 0; right -= (-right & right)) {
			acc += tree[right];
		}
		return acc;
	}
};
signed main() {
	cin >> n >> q;
	adj = vector<vector<int>>(n);
	base = vector<int>(n);
	for (int i = 0; i < n; i++) { cin >> base[i]; }
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	tbegin = vector<int>(n);

	tend = vector<int>(n);
	dfs_arr = vector<int>(n);
	function<int(int, int)> dfs;

	int pos = 0;
	dfs = [&](int last, int actual) {
		dfs_arr[pos] = base[actual];
		tbegin[actual] = pos;
		int mmax = pos;
		pos++;
		for (auto next : adj[actual]) {
			if (next == last) { continue; }
			mmax = dfs(actual, next);
		}
		tend[actual] = mmax;
		return mmax;
	};

	dfs(0, 0);
	BIT bit(dfs_arr);
	for (int qq = 0; qq < q; qq++) {
		int opt;
		cin >> opt;
		if (opt == 2) {
			int pos;
			cin >> pos;
			pos--;
			cout << bit.query(tbegin[pos], tend[pos]) << endl;
		} else {
			int pos, value;
			cin >> pos >> value;
			pos--;
			bit.update(tbegin[pos], value);
		}
	}
}
