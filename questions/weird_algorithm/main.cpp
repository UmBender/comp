#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl '\n'

void weird(int value) {
  if (value == 1) {
  	cout << value << endl;
    return;
  }
  cout << value << ' ';
  if (value % 2 == 0) {
    weird(value / 2);
  }else{
		weird(value * 3 + 1);
	}
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	weird(n);

  return 0;
}
