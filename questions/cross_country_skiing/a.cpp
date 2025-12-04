#include <bits/stdc++.h>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using i128 = __int128;
using VI = vector<i32>;
using VVI = vector<VI>;
using PII = pair<i32,i32>;
using VII = vector<PII>;
using VVII = vector<VII>;

	
i32 m,n;
vector<vector<i64>> grid;
vector<vector<i64>> waypoints;
vector<vector<i64>> used;
i32 p_counter= 0;
i32 n_points = 0;

void setIO(string name = "") {
	if(!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

void clear_used() {
	for(i32 i = 0; i < m; i++) {
		for(i32 j = 0; j < n; j++) {
			used[i][j] = 0; 
		}
	}
}


void dfs(i32 h, i32 w, i64 target, i64 last) {
	if(h >= m || h < 0 || w >= n || w < 0) {
		return;
	}

	if(used[h][w]) {
		return;
	}

	i64 delta = abs(last - grid[h][w]);

	if(target < delta) {
		return;
	}

	if(waypoints[h][w] == 1) {
		p_counter++;
	}
	used[h][w] = true;

	dfs(h - 1, w, target, grid[h][w]);
	dfs(h + 1, w, target, grid[h][w]);
	dfs(h, w - 1, target, grid[h][w]);
	dfs(h, w + 1, target, grid[h][w]);
}

i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	setIO("ccski");
	cin >> m >> n;
	grid= vector<vector<i64>>(m, vector<i64>(n));
	waypoints = vector<vector<i64>>(m, vector<i64>(n));
	used = vector<vector<i64>>(m, vector<i64>(n));
	for(auto &i: grid)  {
		for(i64 &j: i) {
			cin >> j;
		}
	}
	i32 sh, sw;
	for(i32 i = 0; i < m; i++){
		for(i32 j = 0; j < n; j++) {
			cin >> waypoints[i][j];
			if(waypoints[i][j]) {
				sh = i, sw = j;
				n_points++;
			}
		}
	}

	if(n_points == 1 || n_points == 0) {
		cout << 0 << endl; 
		return 0;
	}

	i64 l = 0, r = 1e9 + 100; 
	i64 minimal = INT64_MAX;
	while(l <= r) {
		i64 m = l + (r - l) / 2;
		p_counter = 0;


		dfs(sh, sw, m, grid[sh][sw]);
		clear_used();
		if(p_counter == n_points) {
			minimal = min(minimal,  m);
			r = m - 1;
		}else{
			l = m + 1;
		}
	}
	cout << minimal << endl;


	return 0;
}
