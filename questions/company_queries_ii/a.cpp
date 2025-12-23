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
	vector<vector<i32>> child;
	vector<i32> parent;
	vector<i32> height;
	vector<vector<i32>> bl;
	i32 root = 1;
	i32 n;
	Tree(vector<vector<i32>> _adj)
		: adj(_adj), child(_adj.size()), parent(_adj.size()),
		height(_adj.size()), bl(20, vector<i32>(_adj.size())), n(_adj.size()) 
	{
		function<void(i32, i32, i32)> dfs;
		dfs = [&](i32 actual, i32 last, i32 hh) -> void {
			parent[actual] = last;
			height[actual] = hh;
			for (i32 next : adj[actual]) {
				if (next == last) {
					continue;
				}
				dfs(next, actual, hh + 1);
			}
		};
		parent[1] = 1;
		dfs(1, 1, 0);

		for(i32 i = 1; i < n; i++) {
			bl[0][i] = parent[i];
		}
		for(i32 hh = 1; hh < 19; hh++) {
			for(i32 i = 1; i < n; i++) {
				i32 temp = bl[hh-1][i];
				if(temp == 1) {
					bl[hh][i] = 1;
					continue;
					
				}
				temp = bl[hh-1][temp];
				if(temp == 1) {
					bl[hh][i] = 1;
					continue;
				}
				bl[hh][i] = temp;
			}
		}
	}
	i32 succ(i32 node, i32 k) {
		vector<i32> shifts;
		for(i32 i = 0; i < 20; i ++) {
			if((k >> i) & 1) {
				shifts.push_back(i);
			}
		}
		for(i32 move: shifts) {
			node = bl[move][node];
			if(node == 1) {
				return 1;
			}
		}
		return node;
	}

	i32 lca(i32 first, i32 second) {
		if(height[first] > height[second]) {
			swap(first, second);
		}
		second = succ(second, height[second] - height[first]);
		if(second == 1 || first == 1) {
			return 1;
		}
		if(first == second){ 
			return first;
		}
		while(bl[0][first] != bl[0][second]) {
			bool moved = false;
			for(i32 i = 0; i < 19; i++) {
				if(bl[i][first] != bl[i][second] && bl[i+1][first] == bl[i+1][second]) {
					first = bl[i][first]; 
					second = bl[i][second];
					moved = true;
					break;
				}
			}
			if(!moved) {
				first = bl[19][first];
				second = bl[19][second];
			}
		}
		return bl[0][first];

	}

};

void solution() {
	i32 n, q;
	cin >> n >> q;
	vector<vector<i32>> adj(n+1);
	for(i32 i = 2; i <= n; i++) {
		i32 a;
		cin >> a;
		adj[i].push_back(a);
		adj[a].push_back(i);
	}
	Tree tree(adj);
	for(i32 qq = 0; qq < q; qq++) {
		i32 a,b;
		cin >> a >> b;
		cout << tree.lca(a,b) << endl;
	}
}
