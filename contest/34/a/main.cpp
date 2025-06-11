#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl '\n'

#define MAX_INT ((int)1E18 + 1000)

void solution() {
  int n, m;
  cin >> n >> m;
  int counter = 0;
  int oldx, oldy;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if (counter == 0) {
      counter = 4 * m;
      oldx = x;
      oldy = y;
      continue;
    }
    int left = (oldx + m) - (oldx + x);
    int up = (oldy + m) - (oldy + y);
    counter += 4 * m - 2 * left - 2 * up;
    oldx+= x;
    oldy += y;
  }
  cout << counter << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solution();
  }

  return 0;
}
