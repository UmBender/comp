#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using i128 = __int128;
using VI = vector<i32>;
using VVI = vector<VI>;
using PII = pair<i32,i32>;
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
	i32 n;
	vector<i32> parents;
	vector<vector<i32>> childs;
	vector<i32> height;
	vector<vector<i32>> bl;
	i32 root = 1;

	Tree(vector<vector<i32>> _adj): adj(_adj),n(_adj.size()), parents(_adj.size()),
	childs(_adj.size()), height(_adj.size()), bl(20, vector<i32>(_adj.size(), 1)) {
		function<void(i32,i32,i32)> dfs;
		dfs = [&](i32 actual, i32 last, i32 hh) -> void {
			height[actual] = hh;
			parents[actual] = last;
			for(i32 next: adj[actual]) {
				if(next == last) {
					continue;
				}
				childs[actual].push_back(next);
				dfs(next, actual, hh + 1);
			}
			
		};

		dfs(1, 1, 0);

		for(i32 i = 1; i < n; i++) {
			bl[0][i] = parents[i];
		}
		
		for(i32 hh = 1; hh < 20; hh++) {
			for(i32 i = 1; i < n; i++) {
				i32 actual = bl[hh-1][i];
				actual = bl[hh-1][actual];
				bl[hh][i] = actual;
			}
		}
	}
	
	i32 succ(i32 node, i32 k) {
		if(k == 0) {
			return node;
		}
		for(i32 i = 0; i < 20; i ++) {
			if((k >> i) & 1) {
				node = bl[i][node];
			}
		}
		return node;
	}

	i32 lca(i32 f, i32 s) {
		
		if(height[f] > height[s]) {
			swap(f, s);
		}
		i32 first = f, second = s;
		s = succ(s, height[s] - height[f]);
		if(f == s) {
			return height[second] - height[first];
		}

		while(bl[0][f] != bl[0][s]) {
			bool jumped = false;
			for(i32 i = 19; i >= 1; i --) {
				if(bl[i][f] == bl[i][s] &&
						bl[i - 1][f] != bl[i - 1][s]) {
					f = bl[i - 1][f];
					s = bl[i - 1][s];
					jumped = true;
					break;
				}
			}
			if(!jumped) {
				f = bl[0][f];
				s = bl[0][s];
			}
		}
		i32 lca_node = bl[0][f];
		i32 h_first = abs(height[first] - height[lca_node]);
		i32 h_second = abs(height[second] - height[lca_node]);
		return abs(h_first + h_second);
	}
};

void solution() {
	i32 n, q;
	cin >> n >> q;
	vector<vector<i32>> adj(n + 1);
	for(i32 i = 0; i < n - 1; i++) {
		i32 a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	Tree tree(adj);
	for (i32 qq = 0; qq < q; qq++) { 
		i32 a, b;
		cin >> a >> b;
		cout << tree.lca(a, b) << endl;
	}
}
