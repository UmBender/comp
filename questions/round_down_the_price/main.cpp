#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll

#define endl '\n'

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t > 0) {
    int m;
    cin >> m;
    int x = 1;
    while (x*10<=m) {
      x = x * 10;
    }
    cout << m - x << endl;
    t--;
  }

  return 0;
}
