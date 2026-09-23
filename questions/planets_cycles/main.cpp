#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
#define int ll
#define endl "\n"

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vi adj(n + 1);
	for (int i = 1; i <= n; i++) cin >> adj[i];

	vi dists(n + 1, -1), first(n + 1, -1);
	function<void(int, int)> dfs;

	dfs = [&](int actual, int dist) {
		if (dists[actual] != -1) return;
		if (first[actual] != -1) dists[actual] = dist - first[actual];
		if (first[actual] == -1) first[actual] = dist;
		dfs(adj[actual], dist + 1);
		if (dists[actual] == -1) dists[actual] = dists[adj[actual]] + 1;
	};

	for (int i = 1; i <= n; i++) if (dists[i] == -1) dfs(i, 0);
	for (int i = 1; i <= n; i++) cout << dists[i] << " \n"[i == n];

	return 0;
}

