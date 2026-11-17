#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vvii = vector<vii>;


constexpr int inf = 1e9 + 100;
constexpr int mod = 1e9 + 7;
int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	s--, t--;
	vvi adj(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vi dists(n, inf), cnt(n), used(n), path(n, inf);
	queue<int> qq;
	qq.push(s);
	dists[s] = 0;
	cnt[s] = 1;
	path[s] = -1;
	while (!qq.empty()) {
		int actual = qq.front();
		qq.pop();

		if (used[actual]) continue;
		used[actual] = 1;
		int dist = dists[actual];

		for (int next: adj[actual]) {
			if (dists[next] <= dist) {
				continue;
			}
			if (dist + 1 < dists[next]) {
				cnt[next] = cnt[actual];
				dists[next] = dist + 1;
				path[next] = actual;
				qq.push(next);
				continue;
			}
			cnt[next] += cnt[actual];
			cnt[next] %= mod;
			path[next] = min(path[next], actual);
			qq.push(next);
		}
	}
	if (dists[t] == inf) {
		cout << "-1 0" << endl;
		return 0;
	}
	cout << dists[t] << " " << cnt[t] << endl;
	vector<int> ans;
	for (int temp = t; temp != s; temp = path[temp]) {
		ans.push_back(temp);
	}
	ans.push_back(s);
	reverse(begin(ans), end(ans));
	for (int i = 0; i <= dists[t]; i++) {
		cout << ans[i] + 1 << " \n"[i == dists[t]];
	}
	

	return 0;
}
