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

void solution() {
	i32 n;
	cin >> n;
	vector<vector<i64>> grid(n, vector<i64>(n, 0));
	i32 first = (n - 1) / 2;
	grid[0][first] = 1;
	i32 line = 0, column = (n - 1) / 2;
	for(i32 i =1; i < n * n; i ++) {
		i32 k = grid[line][column];
		i32 r = (line - 1 + n) % n;
		i32 c = (column + 1) % n;
		if(grid[r][c] == 0) {
			grid[r][c] = k + 1;
		}else{
			r = (line + 1) % n;
			c =  column;
			grid[r][c] = k + 1;
		}

		line = r;
		column = c;
	}
	for(i32 i = 0; i < n; i++) {
		for(i32 j = 0; j < n; j++) {
			cout << grid[i][j] << " ";
		}
		cout << "\n";
	}
}
