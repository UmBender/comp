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

  if (n == 1) {
    cout << "1" << endl;
    return 0;
  }
  if (n < 4) {
    cout << "NO SOLUTION" << endl;
    return 0;
  }
  if (n >= 4) {
    for (int i = 2; i <= n; i += 2) {
      cout << i << ' ';
    }
    for (int i = 1; i <= n; i += 2) {
      cout << i << ' ';
    }
  }

  return 0;
}
