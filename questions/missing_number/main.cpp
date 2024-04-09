#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl '\n'

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	int sum = 0;

	for(int i = 0; i < n -1; i++) {
		int k = 0;
		cin >> k;
		sum += k;
	}
	cout << ((n+1)*n)/2 - sum << endl;


  return 0;
}
