#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
using ll = long long;
#define int ll

void solution() {
	int n, q;
	cin >> n >> q;
	vector<int> x(n+1);
	for(int i = 1; i <= n;i++) {
		cin >> x[i];
	}
	while(q--) {
		int opt;
		cin >> opt;
		switch(opt) {
			case 1:
				int c, sx;
				cin >> c >> sx;
				x[c] = sx;
				break;
			case 2:
				int a, b;
				cin >> a >> b;
				cout << abs(x[a] - x[b]) << endl;
				break;
			default:
				break;
		}
	}
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
	solution();

  return 0;
}
