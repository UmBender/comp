#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}
	vector<int> acessed(n + 1);
	vector<int> ans;
	function<bool(int, int)> dfs;
	dfs = [&](int actual, int last) -> bool {
		ans.push_back(actual);
		acessed[actual] = 1;
		for (int next: adj[actual]) {
			if (acessed[next] == 1) {
				ans.push_back(next);
				return true;
			}
			if (acessed[next] == 2) {
				continue;
			}
			if (dfs(next, actual)) {
				return true;
			}
		}
		acessed[actual] = 2;
		ans.pop_back();
		return false;
	};
	bool find = false;
	for (int i = 1; i <= n && !find; i++) {
		if (!acessed[i]) {
			acessed[i] = 1;
			if (dfs(i, -1)) {
				find = true;
			}
			acessed[i] = 2;
		}
	}
	if (!find) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}


	ranges::reverse(ans);
	while (ans.front() != ans.back()) {
		ans.pop_back();
	}
	ranges::reverse(ans);

	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i]<< " \n"[i == ans.size() - 1];
	}

	return 0;
}
