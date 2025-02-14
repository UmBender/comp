#include <bits/stdc++.h>
#include <cmath>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll

void solution() {
  string a, b, c;
  cin >> a >> b >> c;
  vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, MAX_INT));
  dp[0][0] = 0;
  for (int i = 0; i < a.size(); i++) {
    dp[i + 1][0] = dp[i][0] + (a[i] == c[i] ? 0 : 1);
  }
  for (int j = 0; j < b.size(); j++) {
    dp[0][j + 1] = dp[0][j] + (b[j] == c[j] ? 0 : 1);
  }
  for (int i = 1; i <= a.size(); i++) {
    for (int j = 1; j <= b.size(); j++) {
      dp[i][j] =
          min(dp[i][j], dp[i - 1][j] + (a[i - 1] == c[i + j - 1] ? 0 : 1));
      dp[i][j] =
          min(dp[i][j], dp[i][j - 1] + (b[j - 1] == c[i + j - 1] ? 0 : 1));
    }
  }
  cout << dp[a.size()][b.size()] << endl;
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
