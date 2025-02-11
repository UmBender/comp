#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll

void solution() {
  int x, y;
  cin >> x >> y;
  if (x == y) {
    cout << "NO" << endl;
    return;
  }
  if (x < y) {
    if (y - x == 1) {
      cout << "YES" << endl;
      return;
    } else {
      cout << "NO" << endl;
      return;
    }
  }

  while (x > y) {
    x -= 9;
  }
  if (x == y - 1 && x > 0 && y > 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solution();

  return 0;
}
