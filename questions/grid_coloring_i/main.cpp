#include <bits/stdc++.h>
using namespace std;




int main() {
	int n, m;
	cin >> n >> m;
	vector<string> grid(n);
	for (auto &s: grid) {
		cin >> s;
	}
	vector<string> result(n, string(m, ' '));

	const vector<char> poss = {'A', 'B', 'C', 'D'};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			bool find = false;
			for (char next: poss) {
				if (next == grid[i][j]) {
					continue;
				}

				bool okay = true;
				if (i > 0) {
					okay &= result[i - 1][j] != next; 
				}
				if (j > 0) {
					okay &= result[i][j-1] != next;
				}
				if (okay) {
					find = true;
					result[i][j] = next;
				}
			}
			if (!find) {
				cout << -1 << endl;
				return 0;
			}

		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << result[i][j];
		}
		cout << endl;
	}
	return 0;
}
