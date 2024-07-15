#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

void solution() {
	int n;
	cin >> n;
	vector<int> candies(n);
	int min = INT_MAX;
	for(auto &i: candies) {
		cin >> i;
		if(i < min) {
			min = i;
		}
	}
	int counter = 0;
	for(auto &i: candies) {
		counter += (i -min);
	}
	cout << counter << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) {
		solution();
	}

  return 0;
}
