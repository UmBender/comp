#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	vector<pair<int,int>> elements(t);
	for(auto &i: elements) {
		int x,y;
		cin >> x >> y;
		i = make_pair(x,y);
	}
	for(auto i: elements) {
		int x,y;
		x = i.first;
		y = i.second;
		if(x > y) {
			cout << y << " " << x << endl;
		}else{
			cout << x << " " << y << endl;
		}
	}


  return 0;
}
