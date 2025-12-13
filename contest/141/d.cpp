#include <bits/stdc++.h>
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

const i64 INF = 1e9 + 100;

struct Node {
	i64 height, width;
	i64 dist;
	Node(i64 h, i64 w, i64 d): height(h), width(w), dist(d) {}
};

ostream& operator<<(ostream& os, Node& n) {
	os << "height: " << n.height << " widht: " << n.width << " dist: " << n.dist;
	return os;
}


void solution() {
	i32 h, w;
	cin >> h >> w;
	vector<vector<char>> grid(h, vector<char>(w));
	for(i32 i = 0; i < h; i++) {
		string s;
		cin >> s;
		for(i32 j = 0; j < w; j++) {
			grid[i][j] = s[j];
		}
	}
	vector<vector<pair<i32,i32>>> warps(256);
	vector<bool> used(256);
	for(i32 i = 0; i < h; i++) {
		for(i32 j = 0; j < w; j++) {
			if(grid[i][j] <= 'z' && grid[i][j] >= 'a') {
				warps[grid[i][j]].emplace_back(i,j);
			}
		}
	}
	vector<vector<i64>> m_grid(h, vector<i64>(w, INF));
	queue<Node> nodes;
	nodes.emplace(0,0,0);
	m_grid[0][0] = 0;
	vector<pair<i64,i64>>possi = {{1,0},{-1, 0}, {0,1}, {0,-1}};

	while(nodes.size()) {
		Node actual = nodes.front();
		nodes.pop();
		i64 height = actual.height, width = actual.width;
		if(actual.dist > m_grid[height][width]) {
			continue;
		}
		if(actual.dist < m_grid[height][width]) {
			continue;
		}
		i64 n_dist = actual.dist + 1;
		for(auto [hh, ww]: possi) {
			if((hh + height) < h && (hh + height) >= 0
					&& (ww + width) < w && (ww + width) >= 0
					&& grid[hh + height][ww + width] != '#'
			  ) {
				if(m_grid[hh + height][ww + width] > n_dist) {
					m_grid[hh+height][ww + width] = n_dist;
					nodes.emplace(hh + height, ww + width, n_dist);
				}
			}
		}
		if(grid[height][width] != '.' && grid[height][width] != '#') {
			if(!used[grid[height][width]]) {
				for(auto [hh, ww]: warps[grid[height][width]]) {
					if(hh == height && ww == width) {
						continue;
					}
					if(m_grid[hh][ww] > n_dist) {
						m_grid[hh][ww] = n_dist;
						nodes.emplace(hh, ww, n_dist);
					}
				}
				used[grid[height][width]] = true;
			}
		}
	}
	if(m_grid[h-1][w-1] == INF) {
		cout << -1 << endl;
		return;
	}
	cout << m_grid[h-1][w-1] << endl;

	
}
