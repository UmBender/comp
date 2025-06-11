#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl '\n'

#define MAX_INT ((int)1E18 + 1000)

void solution() {
  int x;
  cin >> x;
  int actual = 1;
  for (int i = 2; i < 10E9; i++) {
    actual *= i;
    if (actual == x) {
      cout << i << endl;
      break;
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solution();

  return 0;
}
