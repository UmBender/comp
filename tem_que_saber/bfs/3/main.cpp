#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vvii = vector<vii>;


constexpr int inf = 1e9;
int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m, k;
	cin >> n >> m >> k;
	vi ks(k);
	vvi adj(n);
	for (int i = 0; i < k; i++) {
		cin >> ks[i];
		ks[i]--;
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	// 0 -> dist, 1 -> source, 2 -> actualNode
	using V = array<int, 3>;
	queue<V> qq;
	vii ans(n, make_pair(inf, inf));
	for (int i = 0; i < k; i++) {
		qq.push({0, ks[i], ks[i]});
		ans[ks[i]] = {0, ks[i]};
	}

	while (!qq.empty()) {
		auto [dist, source, node] = qq.front();
		qq.pop();
		if (make_pair(dist, source) > ans[node]) { continue; }
		pii possi = make_pair(dist + 1, source);
		for (int next: adj[node]) {
			if (ans[next] > possi) {
				ans[next] = possi;
				qq.push({dist + 1, source, next});
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (ans[i] == make_pair(inf, inf)) {
			cout << -1 << " " << -1 << endl;
			continue;
		}
		cout << ans[i].first << " " << ans[i].second + 1 << endl;
	}
	
	return 0;
}
