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

  while (n > 0) {
    int y, x;
    cin >> y >> x;
    int square = max(y, x);
    if (square % 2 == 0) {
      cout << square * square + 1 - x - (x > y ? square - y : 0) << endl;

    } else {
      cout << square * square + 1 - y - (y > x ? square - x : 0) << endl;
    }
    n--;
  }

  return 0;
}
