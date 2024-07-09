#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

int32_t main() {
	int n;
	cin >> n;
	vector<pair<int, int>> p(n);
	for(int i = 0; i< n; i++) {
		int x,y;
		cin >> x >> y;
		p[i] = make_pair(x,y);
	}

	for(auto &i: p) {
		if(i.second >= -1) {
			cout << "YES" << endl;
		}else {
			cout << "NO" << endl;
		}
	}


  return 0;
}
