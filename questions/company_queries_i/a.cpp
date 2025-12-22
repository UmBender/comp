#include <bits/stdc++.h>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using i128 = __int128;
using VI = vector<i32>;
using VVI = vector<VI>;
using PII = pair<i32, i32>;
using VII = vector<PII>;
using VVII = vector<VII>;

void solution();

i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	solution();

	return 0;
}

struct Tree {
	vector<vector<i32>> adj;
	vector<vector<i32>> bl;
	vector<vector<i32>> child;
	vector<i32> parent;
	vector<i32> height;
	i32 root;
	Tree(vector<vector<i32>> _adj, i32 _root = 1)
		: adj(_adj), bl(adj.size(), vector<i32>(20, -1)), child(adj.size()),
		parent(adj.size()), height(adj.size()), root(_root) {
			function<void(i32,i32)> dfs;
			height[root] = 0;
			dfs = [&](i32 actual, i32 last) {
				parent[actual] = last;
				for(i32 next: adj[actual]) {
					if(next == last) {
						continue;
					}
					child[actual].push_back(next);
					height[next] = height[actual] + 1;
					dfs(next, actual);
				}
			};
			dfs(root, -1);
			bl[root][0] = -1;
			for(i32 i = 1; i < adj.size(); i++) {
				if(i == root) {
					continue;
				}
				bl[i][0] = parent[i];
			}
			for(i32 h = 1; h < 20; h++) {
				for(i32 node = 1; node < adj.size(); node++) {
					if(bl[node][h-1] == -1){
						continue;
					}
					i32 next= bl[node][h-1];
					if(bl[next][h-1] == -1){
						continue;
					}
					bl[node][h] = bl[next][h-1];
				}
			}
		}
	i32 query(i32 actual, i32 k) {
		vector<i32> converted;
		for(i32 i = 0; i < 21; i ++) {
			i32 actual = (k >> i) & 1;
			if(actual) {
				converted.push_back(i);
			}
		}
		for(i32 p: converted) {
			actual = bl[actual][p];
			if(actual == -1) {
				return -1;
			}
		}
		return actual;
	}

};

void solution() {
	i32 n, q;
	cin >> n >> q;
	vector<vector<i32>> adj(n+1);
	for(i32 i = 2; i <= n;i ++) {
		i32 actual;
		cin >> actual;
		adj[i].push_back(actual);
		adj[actual].push_back(i);
	}
	Tree tree(adj);
	for(i32 qq = 0; qq < q; qq++) {
		i32 actual, k;
		cin >> actual >> k;
		cout << tree.query(actual, k) << endl;
	}

}
