#include <bits/stdc++.h>
using namespace std;
using ll = long long;


struct LCA {
	int n;
	vector<vector<int>> tree;
	vector<vector<int>> lca;
	vector<int> h;
	LCA (vector<vector<int>> &base): n(base.size()), tree(base), lca(n, vector<int>(30)), h(n) {
		function<void(int, int, int)> dfs;
		dfs = [&](int actual, int last, int height) {
			h[actual] = height;
			lca[actual][0] = last;
			for (int next: tree[actual]) {
				if (next == last) continue;
				dfs(next, actual, height + 1);
			}
		};
		dfs(0, -1, 0);
		build();
	}
	void build() {
		for (int i = 1; i < 30; i++) {
			for (int j = 0; j < n; j++) {
				int parent = lca[j][i - 1];
				if (parent != -1) {
					parent = lca[parent][i - 1];
				}
				lca[j][i] = parent;
			}
		}
	}

	int getLca(int first, int second) {
		if (h[first] > h[second]) {
			swap(first, second);
		}
		if (h[first] != h[second]) {
			int delta = h[second] - h[first];
			for (int i = 0; i < 30; i++) {
				if ((delta >> i) & 1) {
					second = lca[second][i];
				}
			}
		}
		if (first == second) {
			return first;
		}
		for (int i = 29; i >= 0; i--) {
			if (lca[first][i] != lca[second][i]) {
				first = lca[first][i];
				second = lca[second][i];
			}
		}
		return lca[first][0];
	}

	int getDist(int first, int second) {
		int par = getLca(first, second);
		int total = (h[first] - h[par]) + (h[second] - h[par]);
		return total;
	}
};

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, q;
	cin >> n >> q;
	vector<vector<int>> adj(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	LCA lca(adj);
	while (q--) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		ll dist = lca.getDist(a, b);
		//cout << "dist: " << dist << endl;
		dist += 2;
		ll acc = dist * (dist - 1);
		acc /= 2;
		dist -= 2;
		acc += (n - 1 - dist);
		cout << acc << endl;
	}

}
