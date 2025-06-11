#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl '\n'

#define MAX_INT ((int)1E18 + 1000)

void solution() {
  int n, a, b;
  cin >> n >> a >> b;
  if ((a - b) & 1) {
    cout << "NO" << endl;

  } else {
    cout << "YES" << endl;
  }
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
