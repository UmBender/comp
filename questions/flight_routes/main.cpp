#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<pair<ll, ll>>> adj(n);
	for (int i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		adj[a].push_back({c, b});
	}
	for (int i = 0; i < n; i++) {
		sort(adj[i].begin(), adj[i].end());
	}
    MinHeap<pair<ll, ll>> minHeap;
	map<ll, ll> counter;
	minHeap.push({0, 0});
	vector<ll> ans;

	while (ans.size() < k && !minHeap.empty()) {
		auto [dist, actual] = minHeap.top();
		minHeap.pop();
		if (counter[actual] >= k) {
			continue;
		}
		counter[actual]++;

		if (actual == n - 1) {
			ans.push_back(dist);
		}
		for (auto [cost, next]: adj[actual]) {
			minHeap.push({dist + cost, next});
		}
	}

	sort(begin(ans), end(ans));
	for (int i = 0; i < k; i++) {
		cout << ans[i] << " \n"[i == k - 1];
	}

	return 0;
}
