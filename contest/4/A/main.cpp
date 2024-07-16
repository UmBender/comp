#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10
void solution() {
	vector<int> val(3);
  cin >> val[0] >> val[1] >> val[2];
	for(int i = 0; i < 5; i++) {
		sort(val.begin(), val.end());
		val[0]++;
	}
	int prod = 1;
	for(auto i: val) {
		prod *=i;
	}
	cout << prod << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solution();
  }

  return 0;
}
