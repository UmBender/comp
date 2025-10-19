#include <bits/stdc++.h>
using namespace std;
#define int int64_t

void solution();
signed main() {
	int t;
	cin >> t;
	while (t--) { solution(); }
}
void solution() {
	int n;
	cin >> n;
	vector<vector<int>> adj(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	if (n == 2) {
		cout << 2 << endl;
		cout << 1 << endl;
		cout << "2 1" << endl;
		return;
	}
	vector<int> color(n);
	function<void(int, int)> dfs;
	dfs = [&](int actual, int last) {
		int next_color = 1 - color[actual];
		for (int next : adj[actual]) {
			if (next == last) { continue; }
			color[next] = next_color;
			dfs(next, actual);
		}
	};
	dfs(n - 1, n - 1);
	vector<int> counter(n);
	int comps = n;
	for (int i = 0; i < n; i++) { counter[i] = adj[i].size(); }
	set<int> white_leaf, black_leaf;
	vector<int> used(n);
	for (int i = 0; i < n-1; i++) {
		if (counter[i] == 1) {
			used[i] = 1;
			if (color[i]) {
				black_leaf.insert(i);
			} else {
				white_leaf.insert(i);
			}
		}
	}
	vector<pair<int, int>> ops;
	int actual_color = 1 - color[0];
	while (comps > 1) {
		if (actual_color == 0) {
			if (white_leaf.empty()) {
				actual_color = 1 - actual_color;
				ops.push_back({1, 0});
			} else {
				int actual_leaf = *white_leaf.begin();
				for (int next : adj[actual_leaf]) {
					if (used[next]) { continue; }
					counter[next]--;
					if (counter[next] <= 1 && next != n - 1) {
						black_leaf.insert(next);
						used[next] = true;
					}
				}
				white_leaf.erase(actual_leaf);
				comps--;
				ops.push_back({2, actual_leaf});
				ops.push_back({1, 0});

				actual_color = 1 - actual_color;
			}

		} else {
			if (black_leaf.empty()) {
				actual_color = 1 - actual_color;
				ops.push_back({1, 0});
			} else {
				int actual_leaf = *black_leaf.begin();
				for (int next : adj[actual_leaf]) {
					if (used[next]) { continue; }
					counter[next]--;
					if (counter[next] <= 1 && next != n - 1) {
						white_leaf.insert(next);
						used[next] = true;
					}
					black_leaf.erase(actual_leaf);
					comps--;
					ops.push_back({2, actual_leaf});
					ops.push_back({1, 0});
					actual_color = 1 - actual_color;
				}
			}
		}
	}
	cout << ops.size() << endl;
	for (auto [a, b] : ops) {
		if (a == 1) {
			cout << 1 << endl;
		} else {
			cout << 2 << " " << b + 1 << endl;
		}
	}
}
