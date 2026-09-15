#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int MAX = 1e9;

int32_t main() {
	int n, k;
	cin >> n >> k;
	vector<vector<int>> x(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> x[i][j];
		}
	}
	vector<map<pair<int, int>, int>> minByGrid(k + 1); 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			pair<int, int> actual = {i, j};
			minByGrid[x[i][j]][actual] = 1e9;
			if (x[i][j] == 1) {
				minByGrid[x[i][j]][actual] = 0;
			}
		}
	}

	auto dist = [](pair<int, int> last, pair<int, int> actual) -> int {
		return abs(last.first - actual.first) + abs(last.second - actual.second);
	};
	for (int kk = 2; kk <= k; kk++) {
		for (auto &[lastPos, lastVal]: minByGrid[kk - 1]) {
			for (auto &[actualPos, actualVal]: minByGrid[kk]) {
				int totalDist = lastVal + dist(lastPos, actualPos);
				actualVal = min(actualVal, totalDist);
			}
		}
	}
	int mmin = MAX;
	for (auto [k, v]: minByGrid[k]) {
		mmin = min(v, mmin);
	}
	if (mmin == MAX) {
		mmin = -1;
	}
	cout << mmin << endl;

	return 0;
}
