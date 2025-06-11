#include <bits/stdc++.h>
#include <numeric>

using namespace std;

using ll = long long;
#define int ll
#define endl '\n'

#define MAX_INT ((int)1E18 + 1000)

void solution() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<vector<int>> a(n, vector<int>(m));
  for (auto &i : a) {
    for (auto &j : i) {
      cin >> j;
    }
  }
  int i = 0;
  int j = 0;
  for (auto l : s) {
    if (l == 'D') {
      int su = 0;
      for (int k = 0; k < m; k++) {
        su += a[i][k];
      }
      a[i][j] = -su;
      i++;
    } else {
      int su = 0;
      for (int k = 0; k < n; k++) {
        su += a[k][j];
      }
      a[i][j] = -su;
      j++;
    }
  }

  int su = 0;
  for (int i = 0; i < m; i++) {
    su += a[n - 1][i];
  }
  a[n - 1][m - 1] = -su;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << a[i][j] << " \n"[j == m - 1];
    }
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
