#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10
void solution() {
  int a, b, c;
  cin >> a >> b >> c;
	if(a < b && b < c) {
		cout << "STAIR" << endl;
	}else if(a < b && c < b) {
		cout << "PEAK" << endl;
	}else{
		cout << "NONE" << endl;
	}
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
