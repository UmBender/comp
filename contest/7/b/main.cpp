#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

void solution() {
  int n, k;
  cin >> n >> k;
	vector<string> grid(n);
	for(auto &i: grid) {
		cin >> i;
	}
	for(int i = 0; i < n; i+=k) {
		for(int j = 0; j < n; j+=k) {
			cout << grid[i][j];
		}
		cout << endl;
	}
}
int32_t main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solution();
  }

  return 0;
}
