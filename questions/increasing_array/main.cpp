#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  int x[n];
  for (int i = 0; i < n; i++) {
		cin >> x[i];
  }
	int counter = 0;
	for (int i = 1; i < n; i++) {
		if(x[i] < x[i-1]) {
			counter += x[i-1]-x[i];
			x[i] = x[i-1];
		}
	}
	cout << counter << endl;

  return 0;
}
