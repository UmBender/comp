#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	vector<int> tmp;
	function<void(int, int)> dfs;
	dfs = [&](int rest, int pos) {
		if (pos == n && rest == 0) {
			for (int i = 0; i < n; i++) {
				cout << tmp[i] << " \n"[i == n - 1];
			}
			return;
		}

		for (int i = 0; i * (pos + 1) <= rest && pos < n; i++) {
			int removing = i * (pos + 1);
			tmp.push_back(i);
			dfs(rest - removing, pos + 1);
			tmp.pop_back();
		}
	};
	dfs(k, 0);
	return 0;
}
