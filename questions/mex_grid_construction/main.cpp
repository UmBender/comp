#include <bits/stdc++.h>
using namespace std;


constexpr int MAX_N = 110;
int grid[MAX_N][MAX_N];

int main() {
	int n;
	cin >> n;

	auto getMex = [&](int i, int j) -> int {
		vector<int> a(2 * MAX_N, 1);
		for (int k = 0; k < i; k++) {
			a[grid[k][j]] = 0;
		}	
		for (int k = 0; k < j; k++) {
			a[grid[i][k]] = 0;
		}

		
		for (int i = 0; i < a.size(); i++) {
			if (a[i]) {
				return i;
			}
		}
		
		return MAX_N * 2 + 1;
	};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			grid[i][j] = getMex(i, j);
			cout << grid[i][j] << " ";
		}
		cout << "\n";
	}
	

	return 0;
}
