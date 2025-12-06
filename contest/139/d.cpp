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


void solution() {
	i32 n, m;
	cin >> n >> m;
	vector<vector<i32>>adj(n + 1);
	vector<vector<i32>> rev(n + 1);
	for(i32 i = 0; i < m; i++) {

		i32 a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		rev[b].push_back(a);
	}	   
	i32 q; cin >> q;
	vector<i32> color(n + 1);
	auto populate = [&](i32 node) {
		if(color[node]) {
			return;
		}
		queue<i32> nodes;
		nodes.push(node);
		while(nodes.size()) {
			i32 actual_node = nodes.front();
			nodes.pop();
			if(color[actual_node]) {
				continue;
			}
			color[actual_node] = 1;
			for(i32 next: rev[actual_node]) {
				if(color[next]) {
					continue;
				}
				nodes.push(next);
			}
		}
	};
	for(i32 qq = 0; qq < q; qq++) {
		i32 opt, v;
		cin >> opt >> v;
		if(opt == 1) {
			populate(v);
		}else{
			if(color[v]) {
				cout << "Yes" << endl;
			}else{
				cout << "No" << endl;
			}

		}

	}


}
