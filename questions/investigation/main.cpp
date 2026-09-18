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

constexpr int inf = 1e17 + 100;
constexpr int mod = 1e9 + 7;

template<typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vvii adj(n);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		adj[a].emplace_back(b, c);
	}
	vi shortPath(n, inf), shortPathCount(n), shortPathMax(n, 0), shortPathMin(n, inf);
	MinHeap<pii> nodes;
	nodes.push({0, 0});
	shortPath[0] = 0;
	shortPathCount[0] = 1;
	shortPathMin[0] = 0;

	auto updateSame = [&](int actual, int next) {
		shortPathCount[next] += shortPathCount[actual];
		shortPathCount[next] %= mod;
		shortPathMin[next] = min(shortPathMin[next], shortPathMin[actual] + 1);
		shortPathMax[next] = max(shortPathMax[next], shortPathMax[actual] + 1);
	};

	auto updateDiff = [&](int actual, int next, int edgeCost) {
		shortPath[next] = shortPath[actual] + edgeCost;
		shortPathCount[next] = shortPathCount[actual];
		shortPathMin[next] = shortPathMin[actual] + 1;
		shortPathMax[next] = shortPathMax[actual] + 1;
	};

	int iter =0;

	while (!nodes.empty()) {
		auto [cost, node] = nodes.top();
		iter++;
		nodes.pop();
		if (cost > shortPath[node]) continue;

		for (auto [next, edgeCost]: adj[node]) {
			if (shortPath[next] == shortPath[node] + edgeCost) {
				updateSame(node, next);
				continue;
			}
			if (shortPath[next] > shortPath[node] + edgeCost) {
				updateDiff(node, next, edgeCost);
				nodes.emplace(shortPath[next], next);
			}
		}	
	}

	cerr << iter << endl;
	cout << shortPath[n - 1] << " " << shortPathCount[n - 1] << " " << shortPathMin[n - 1] << " " << shortPathMax[n - 1] << endl;


	return 0;
}
