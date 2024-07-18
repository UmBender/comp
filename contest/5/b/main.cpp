#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10
void solution() {
  int n;
  cin >> n;
  int size = 2 * n;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (((i / 2) % 2 == 0 && (j / 2) % 2 == 0) ||
          ((i / 2) % 2 == 1 && (j / 2) % 2 == 1)) {
        cout << "#";
      } else {
        cout << ".";
      }
    }
    cout << endl;
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
