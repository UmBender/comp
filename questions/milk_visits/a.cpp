#include <bits/stdc++.h>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using VI = vector<i32>;
using VVI = vector<VI>;
using PII = pair<i32,i32>;
using VII = vector<PII>;
using VVII = vector<VII>;


void setIO(string path = "") {
	if(path.size()) {
		freopen((path + ".in").c_str(), "r", stdin);
		freopen((path + ".out").c_str(), "w", stdout);
	}
}

void solution();
i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	setIO("milkvisits");
	solution();
	return 0;
}

void solution() {
	i32 n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	vector<vector<i32>> adj(n+1);
	for(i32 i = 0; i < n - 1; i ++) {
		i32 a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<i32> component(n + 1);
	function<void(i32,i32,i32,char)> dfs;
	dfs = [&](i32 actual, i32 last, i32 comp, char letter) {
		for(i32 next: adj[actual]) {
			if(next == last) {
				continue;
			}	
			if(s[next-1] != letter) {
				continue;
			}
			component[next] = comp;
			dfs(next, actual, comp, letter);
		}
	};
	for(i32 i = 1; i < n; i ++) {
		if(!component[i]) {
			component[i] = i;
			dfs(i, i, i, s[i-1]);
		}
	}
	string result;
	for(i32 mm = 0; mm < m; mm++) {
		i32 first, second;
		cin >> first >> second;
		char letter;
		cin >> letter;
		if(component[first] != component[second]) {
			result += "1";
			continue;
		}
		if(s[first - 1] == letter) {
			result += "1";
			continue;
		}
		result += "0";
	}
	cout << result << "\n";
		
}
