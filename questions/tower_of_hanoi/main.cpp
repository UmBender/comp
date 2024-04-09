#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl '\n'

void hanoi(int height, int init, int end) {
	if(height == 1) {
		cout << init << " " << end << endl;
		return;
	}
	int middle = 6 - init - end;
	hanoi(height -1,init, middle);
	cout << init << " " << end << endl;
	hanoi(height -1, middle, end);
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	cout << (1 << n) -1 << endl;

	hanoi(n,1,3);


  return 0;
}
