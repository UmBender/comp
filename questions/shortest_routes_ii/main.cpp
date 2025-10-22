#include <bits/stdc++.h>
using namespace std;
#define int int64_t
void solution();
signed main() { solution(); }
void solution() {
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<int>> adj(n, vector<int>(n, 1e18));
	for (int i = 0; i < n; i++) { adj[i][i] = 0; }
	for (int mm = 0; mm < m; mm++) {
		int a, b, w;
		cin >> a >> b >> w;
		a--, b--;
		adj[a][b] = min(w, adj[a][b]);
		adj[b][a] = min(w, adj[b][a]);
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
	for (int qq{0}; qq < q; qq++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		int result = adj[a][b];
		if (result == 1e18) {
			cout << -1 << endl;
			continue;
		}
		cout << result << endl;
	}
}
