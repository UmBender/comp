#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

	int n,x;
	cin >> n >> x;
	vector<int> av(n);
	map<int,int> am;

	for(int i = 0; i < n; i++) {
		int value;
		cin >> value;
		av[i] = value;
		am[value] = i;
	}

	bool find = false;
	for(int i = 0; i < n; i++) {
		int target = x - av[i];
		auto it = am.find(target);
		if(it == am.end()) {
			continue;
		}
		if(it->second != i) {
			cout << i + 1<< " " << it->second + 1<< endl;
			find = true;
			break;
		}
	}
	if(!find) {
		cout << "IMPOSSIBLE" << endl;
	}

  return 0;
}
