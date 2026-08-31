#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;


#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); i++)

mt19937 rng(random_device{}());

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> p(n - 1);
	vector<vector<int>> adj(n);
	for (int i = 0; i < n - 1; i++) {
		cin >> p[i];
		p[i]--;
	}
	for (int i = 0; i < n - 1; i++) {
		adj[p[i]].push_back(i + 1);
	}
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	vector<int> ans(n);
	vector<int> temp;
	function<void(int)> dfs;
	dfs = [&](int actual) {
		bool remove = false;
		int last, pos;
		auto iter = lower_bound(begin(temp), end(temp), v[actual]);
		if (iter == end(temp)) {
			remove = true;
			temp.push_back(v[actual]);
		} else {
			pos = iter - begin(temp);
			last = temp[pos];
			temp[pos] = v[actual];
		}
		ans[actual] = sz(temp);
		for (int next: adj[actual]) {
			dfs(next);
		}
		if (remove) {
			temp.pop_back();
		} else {
			temp[pos] = last;
		}
	};
	dfs(0);
	for (int i = 1; i < n; i++) {
		cout << ans[i] << " \n"[i == n - 1];
	}

	return 0;
}

