#include <bits/stdc++.h>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using i128 = __int128;
using VI = vector<i32>;
using VVI = vector<VI>;
using PII = pair<i32,i32>;
using VII = vector<PII>;
using VVII = vector<VII>;

void setIO(string name = "") {
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	setIO("factory");
	i32 n;
	cin >> n;
	vector<vector<i32>> adj(n + 1);
	for (i32 i = 0; i < n - 1; ++i) {
		i32 a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}
	vector<i32> counter(n + 1);
	auto bfs = [&](i32 base_node) {
		queue<i32> nodes;
		nodes.push(base_node);
		vector<bool> used(n + 1);
		while (nodes.size()) {
			i64 actual = nodes.front();
			nodes.pop();
			if (used[actual]) {
				continue;
			}
			counter[actual]++;
			for (i64 next: adj[actual]) {
				nodes.push(next);
			}
		}
	
	};

	for (i32 i = 1; i <= n; i++) {
		bfs(i);
	}

	for (i32 i = 1; i <= n; i++) {
		if (counter[i] == n) {
			cout << i << "\n";
			return 0;
		}
	}


	cout << - 1 << "\n";

	return 0;
}
