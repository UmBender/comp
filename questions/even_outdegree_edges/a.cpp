#include<bits/stdc++.h>
using namespace std;

using i32 = int32_t;
using i64 = int64_t;
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
	vector<set<i32>> adj(n + 1);
	for(i32 i = 0; i < m; i++) {
		i32 a, b;
		cin >> a >> b;
		adj[a].insert(b);
		adj[b].insert(a);
	}
	if(m % 2) {
		cout << "IMPOSSIBLE" << '\n';
		return;
	}
	vector<i32> used(n + 1);
	vector<i32> colors(n + 1);

	auto bfs = [&](i32 actual, i32 color) {
		queue<i32> nodes;
		nodes.push(actual);
		while(nodes.size()) {
			auto actual = nodes.front();
			nodes.pop();
			for(i32 next: adj[actual]) {
				if(colors[next]){
					continue;
				}
				colors[next] = color;
				nodes.push(next);
			}
		}
	};	
	map<i32,i32> co;
	for(i32 i = 1; i <= n; i++) {
		if(!colors[i]) {
			bfs(i, i);
		}
	}
	for(i32 i = 1; i <= n; i++) {
		co[colors[i]] += adj[i].size();
	}
	for(auto [k,v]: co) {
		if((v/2) % 2) {
			cout << "IMPOSSIBLE" << endl;
			return;
		}
	}

	
	vector<pair<i32,i32>> solution;
	
	fill(used.begin(), used.end(), false);
	vector<i32> counter(n + 1);
	vector<bool> temp(n + 1);
	function<void(i32)> dfs1;
	dfs1 = [&](i32 actual) {
		temp[actual] = true;
		used[actual] = true;
		for(i32 next: adj[actual]) {
			if(temp[next]) {
				continue;
			}else if(used[next]) {
				if(counter[next] % 2) {
					counter[next]++;
					solution.push_back({next, actual});
				}else{
					counter[actual]++;
					solution.push_back({actual, next});
				}

			}else {
				dfs1(next);
				if(counter[next] % 2) {
					counter[next]++;
					solution.push_back({next, actual});
				}else{
					counter[actual]++;
					solution.push_back({actual, next});
				}

			}
		}
		temp[actual] = false;
	};
	for(i32 i = 1; i <= n; i++) {
		if(!used[i]) {
			dfs1(i);
		}
	}
	for(i32 i = 0; i < solution.size(); i++) {
		cout << solution[i].first << " " << solution[i].second << endl;
	}
}


