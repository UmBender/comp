#include <bits/stdc++.h>



using namespace std;
using ll = long long;
#define int ll 

static constexpr int MOD = 1e9 + 7;
static constexpr int MAX_S = 2010;

pair<int,int> nxt[MAX_S][MAX_S];
int grid[MAX_S][MAX_S];
int mmin[MAX_S][MAX_S];
int counter[MAX_S][MAX_S];
int r, c;

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> grid[i][j];
		}
	}
	for (int i = 0; i < r; i++) {
		stack<pair<int,int>> s;
		for (int j = c - 1; j >= 0; j--) {
			while (!s.empty() && s.top().first <= grid[i][j]) {
				s.pop();
			}
			if (!s.empty()) {
				nxt[i][j].second = s.top().second;
			} else {
				nxt[i][j].second = -1;
			}
			s.emplace(grid[i][j], j);
		}
	}
	for (int j = 0; j < c; j++) {
		stack<pair<int,int>> s;
		for (int i = r - 1; i >= 0; i--) {
			while (!s.empty() && s.top().first <= grid[i][j]) {
				s.pop();
			}
			if (!s.empty()) {
				nxt[i][j].first = s.top().second;
			} else {
				nxt[i][j].first	= -1;
			}
			s.emplace(grid[i][j], i);
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			mmin[i][j] = 1e18;
		}
	}
	counter[0][0] = 1;
	mmin[0][0] = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int nc = nxt[i][j].second;
			int nr = nxt[i][j].first;
			if (nc != -1 && mmin[i][j] + 1 <= mmin[i][nc]) {
				if (mmin[i][nc] == mmin[i][j] + 1) {
					counter[i][nc] += counter[i][j];
					counter[i][nc] %= MOD;
				} else {
					counter[i][nc] = counter[i][j];
					mmin[i][nc] = mmin[i][j] + 1;
				}
			}
			if (nr != -1 && mmin[i][j] + 1 <= mmin[nr][j]) {
				if (mmin[nr][j] == mmin[i][j] + 1) {
					counter[nr][j] += counter[i][j];
					counter[nr][j] %= MOD;
				} else {
					counter[nr][j] = counter[i][j];
					mmin[nr][j] = mmin[i][j] + 1;
				}
			}

		}
	}

	if (mmin[r - 1][c - 1] == 1e18) {
		cout << "-1 0" << endl;
		return 0;
	}
	cout << mmin[r - 1][c - 1] << " "  << counter[r-1][c-1] << endl;


	
	return 0;
}

