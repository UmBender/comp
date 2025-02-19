// #include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll
void solution() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  map<int, int> colors;
  for (auto &i : a) {
    for (auto &j : i) {
      cin >> j;
      {
        colors[j] = 1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j > 0) {
        if (a[i][j] == a[i][j - 1]) {
          colors[a[i][j]] = 2;
        }
      }
      if (j < m - 1) {
        if (a[i][j] == a[i][j + 1]) {
          colors[a[i][j]] = 2;
        }
      }
      if (i > 0) {
        if (a[i][j] == a[i - 1][j]) {
          colors[a[i][j]] = 2;
        }
      }
      if (i < n - 1) {
        if (a[i][j] == a[i + 1][j]) {
          colors[a[i][j]] = 2;
        }
      }
    }
  }

  int twos = 0;
  for (auto &[i, j] : colors) {
    if (j == 2) {
      twos++;
    }
  }
  int counter = 0;
  if (twos > 0) {

    for (auto &[i, j] : colors) {
      counter += j;
    }
    counter -= 2;
  } else {
    for (auto &[_, j] : colors) {
      counter += j;
    }
    counter--;
  }
  cout << counter << endl;
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
