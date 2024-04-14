#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

void solution() {
  int a, b;
  cin >> a >> b;
  int y = (-a + 2 * b);
  int x = (2 * a - b);
  if (y % 3 == 0 && x % 3 == 0 && y >= 0 && x>= 0) {
    cout << "YES" << endl;
    return;
  }
  cout << "NO" << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  while (n > 0) {

    solution();
    n--;
  }

  return 0;
}
