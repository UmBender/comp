#include <bits/stdc++.h>
using namespace std;
#define int int64_t
void solution();
signed main() { solution(); }

void solution() {
	int a, b;
	cin >> a >> b;
	if (a < b) { swap(a, b); }
	vector<vector<int>> mmin(a + 1, vector<int>(b + 1, 1e18));
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			if (i == j) {
				mmin[i][j] = 0;
				continue;
			}
			for (int k = 1; k + 1 <= j; k++) {
				mmin[i][j] = min(mmin[i][j], mmin[i][k] + mmin[i][j - k] + 1);
			}
			for (int k = 1; k + 1 <= i; k++) {
				mmin[i][j] = min(mmin[i][j], mmin[k][j] + mmin[i - k][j] + 1);
			}
		}
	}
	cout << mmin[a][b] << endl;
}
