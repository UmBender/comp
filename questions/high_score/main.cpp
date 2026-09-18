#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pii = pair<ll, ll>;
using vii = vector<pii>;
using vvii = vector<vii>;
#define int ll
#define endl "\n"

struct Edge {
	int a, b, c;
};
constexpr int INF = 1e16;

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<Edge> edges(m);
	vvi adj(n), radj(n);
	for (int edge = 0; edge < m; edge++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		edges[edge] = {a, b, -c};
		adj[a].push_back(b);
		radj[b].push_back(a);
	}

	function<void(int, vvi&, vi&)> dfs;
	vi reach(n);
	vi rreach(n);

	reach[0] = 1;
	rreach[n - 1] = 1;

	dfs = [&](int actual, vvi& vadj, vi& vreach) {
		for (int next: vadj[actual]) {
			if (vreach[next]) continue;
			vreach[next] = 1;
			dfs(next, vadj, vreach);
		}
	};

	dfs(0, adj, reach);
	dfs(n - 1, radj, rreach);


	vector<int> d(n, INF);
	d[0] = 0;
	for (int i = 0; i < n - 1; i++) {
		for (Edge edge: edges) {
			if (d[edge.a] + edge.c < d[edge.b]) {
				d[edge.b] = max(-INF, d[edge.a] + edge.c);
			}
		}
	}
	for (Edge edge: edges) {
		int last = d[edge.b];
		if (d[edge.a] + edge.c < d[edge.b]) {
			d[edge.b] = d[edge.a] + edge.c;
		}
		int actual = d[edge.b];
		if (actual < last && reach[edge.b] && rreach[edge.b]) {
			cout << -1 << endl;
			return 0;
		}
	}
	cout << -d[n - 1] << endl;
	return 0;
}
