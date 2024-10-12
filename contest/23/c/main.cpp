#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

void __dbg() { cerr << endl; }
template <typename T> void __dbg(T t) { cerr << t << endl; }
template <typename T, typename... TRest> void __dbg(T first, TRest... rest) {
  cerr << first << ", ";
  __dbg(rest...);
}
#define dbg(...)                                                               \
  do {                                                                         \
    cerr << "DBG> " << "(" << #__VA_ARGS__ << ") = ";                          \
    __dbg(__VA_ARGS__);                                                        \
  } while (0)

void solution() {
  int n;
  cin >> n;
  vector<vector<char>> grid(n, vector<char>(n));
  vector<vector<char>> ngrid(n, vector<char>(n));
  for (auto &i : grid) {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++) {
      i[j] = s[j];
    }
  }

  for (int i = 0; i < n / 2; i++) {
    if (i % 4 == 0) {
      for (int j = i; j < n - i; j++) {
        ngrid[i][j] = grid[n - j - 1][i];
        ngrid[j][n - i - 1] = grid[i][j];
        ngrid[n - i - 1][n - j - 1] = grid[j][n - i - 1];
        ngrid[n - j - 1][i] = grid[n - i - 1][n - j - 1];
      }

    } else if (i % 4 == 1) {
      for (int j = i; j < n - i; j++) {
        ngrid[i][j] = grid[n - i - 1][n - j - 1];
        ngrid[j][n - i - 1] = grid[n - j - 1][i];
        ngrid[n - i - 1][n - j - 1] = grid[i][j];
        ngrid[n - j - 1][i] = grid[j][n - i - 1];
      }
    } else if (i % 4 == 2) {
      for (int j = i; j < n - i; j++) {
        ngrid[i][j] = grid[j][n - i - 1];
        ngrid[j][n - i - 1] = grid[n - i - 1][n - j - 1];
        ngrid[n - i - 1][n - j - 1] = grid[n - j - 1][i];
        ngrid[n - j - 1][i] = grid[i][j];
      }
    } else {
      for (int j = i; j < n - i; j++) {
        ngrid[i][j] = grid[i][j];
        ngrid[j][n - i - 1] = grid[j][n - i - 1];
        ngrid[n - i - 1][n - j - 1] = grid[n - i - 1][n - j - 1];
        ngrid[n - j - 1][i] = grid[n - j - 1][i];
      }
    }
  }

  for (auto &i : ngrid) {
    for (auto &j : i) {
      cout << j;
    }
    cout << endl;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solution();

  return 0;
}
