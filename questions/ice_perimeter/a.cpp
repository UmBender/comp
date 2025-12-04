#include <bits/stdc++.h>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using VI = vector<i32>;
using VVI = vector<VI>;
using PII = pair<i32,i32>;
using VII = vector<PII>;
using VVII = vector<VII>;

void setIO(string name = "") {  
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

const i64 MAX_SIZE = 1010;
char grid[MAX_SIZE][MAX_SIZE];
i32 area[MAX_SIZE * MAX_SIZE];
i32 perimeter[MAX_SIZE * MAX_SIZE];
i32 tgrid[MAX_SIZE][MAX_SIZE];
i32 n;

void dfs(i32 h, i32 w, i32 group) {
	if(h >= n || h < 0 || w >= n || w < 0) {
		perimeter[group]++;
		return;
	}
	if(!grid[h][w]) {
		perimeter[group]++;
		return;
	}
	if(tgrid[h][w] == 0) {
		tgrid[h][w] = group;
		area[group] ++;
		dfs(h + 1, w, group);
		dfs(h - 1, w, group);
		dfs(h, w + 1, group);
		dfs(h, w - 1, group);
	}
}

i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	setIO("perimeter");
	cin >> n;
	for(i32 i = 0; i < n; i++) {
		string s;cin >> s;
		for(i32 j = 0; j < n; j++) {
			grid[i][j] = s[j] == '#';
		}
	}

	i32 m = 1;
	for(i32 i = 0; i < n; i++) {
		for(i32 j = 0; j < n; j++) {
			if(tgrid[i][j] == 0 && grid[i][j]) {
				area[m] = 0;
				perimeter[m] = 0;
				dfs(i, j, m);
				m++;
			}
		}
	}
	i32 m_area = 0; 
	i32 m_perimeter = INT32_MAX;

	for(i32 i =1; i < m; i++) {
		if(area[i] > m_area) {
			m_area = area[i];
			m_perimeter = perimeter[i];
		}else if(area[i] == m_area) {
			m_perimeter = min(m_perimeter, perimeter[i]);
		}
	}

	cout << m_area << " " << m_perimeter << endl;
	return 0;

}

