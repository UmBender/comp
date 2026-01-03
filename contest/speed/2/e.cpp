#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i32 = int32_t;
using i128 = __int128;
using VI = vector<i32>;
using VVI = vector<VI>;
using PII = pair<i32, i32>;
using VII = vector<PII>;
using VVII = vector<VII>;
// debug stuff, no need to type at first
void PRINT(auto x) { cerr << '\t' << x << endl; }
void PRINT(const char *name, auto... x) {
	cerr << "DEBUG> "<< name << " = [" << endl;
	(PRINT(x), ...);
	cerr << ']' << endl;
}
# define DEBUG(...) PRINT(#__VA_ARGS__, __VA_ARGS__)
// #define int i64

const i64 MOD = 998244353;


struct Tree {
	vector<vector<i32>> adj;
	vector<vector<i32>> child;
	vector<i32> parent;
	vector<i32> height;
	Tree(vector<vector<i32>> _adj): adj(_adj), child(_adj.size()), parent(_adj.size()), height(_adj.size()) {
		function<void(i32,i32,i32)> dfs;
		dfs = [&](i32 actual, i32 last, i32 hh) {
			height[actual] = hh;
			parent[actual] = last;
			for (i32 next: adj[actual]) {
				if (next == last) {
					continue;
				}
				child[actual].push_back(next);
				dfs(next, actual, hh + 1);
			}

		};
		dfs(1, 1, 0);

	}
	vector<pair<i32,i32>> lift(i32 first, i32 second) {
		vector<pair<i32, i32>> first_path, second_path;
		while(height[first] > height[second]) {
			first_path.push_back({first, parent[first]});
			first = parent[first];
		}
		while(height[second] > height[first]) {
			second_path.push_back({parent[second], second});
			second = parent[second];
		}
		if(second == first) {
			for (i32 i = second_path.size() - 1; i >= 0; i--) {
				first_path.push_back(second_path[i]);
			}
			return first_path;
		}
		while(first != second) {
			first_path.push_back({first, parent[first]});
			second_path.push_back({parent[second], second});
			first = parent[first];
			second = parent[second];
		}
		for (i32 i = second_path.size() - 1; i >= 0; i--) {
			first_path.push_back(second_path[i]);
		}
		return first_path;

	}
};
i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	i32 n, m, k;
	cin >> n >> m >> k;
	vector<i32> a(m);
	for (i32 i = 0; i < m; i++) {
		cin >> a[i];
	}
	vector<vector<i32>> adj(n + 1);
	vector<pair<i32,i32>> ed_list;
	for (i32 i = 0; i < n - 1; i++) {
		i32 u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);

		ed_list.emplace_back(u, v);
	}
	Tree t(adj);
	map<pair<i32,i32>, i32> counter;
	for (i32 i = 0; i < m - 1; i++) {
		i32 begin = a[i];
		i32 end = a[i + 1];
		vector<pair<i32,i32>> result = t.lift(begin, end);
		for (auto [f, s]: result) {
			if (f > s) {
				swap(f, s);
			}
			counter[make_pair(f, s)]++;
		}
	}
	i32 zeros = 0;
	zeros = n - 1 - counter.size();
	map<i64, i64> dp;
	vector<i64> count;
	for (auto [k, v]: counter) {
		count.push_back(v);
	}
	
	dp[0] = 1;
	for (i32 i = 0; i < count.size(); i++) {
		map<i64,i64> temp;
		for (auto [k, v]: dp) {
			i64 r_next = k + count[i];
			i64 b_next = k - count[i];
			temp[r_next] += v;
			temp[r_next] %= MOD;
			temp[b_next] += v;
			temp[b_next] %= MOD;
		}
		swap(temp, dp);
	}
	for (i32 i = 0; i < zeros; i++) {
		dp[k] *= 2;
		dp[k] %= MOD;
	}
	cout << dp[k] << endl;

	return 0;
}

