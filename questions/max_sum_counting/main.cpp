#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define MOD 998244353
void solution() {

  int64_t n;
  cin >> n;
  vector<pair<int64_t, int64_t>> ab(n);
  for (int64_t i = 0; i < n; i++) {
    cin >> ab[i].first;
  }

  for (int64_t i = 0; i < n; i++) {
    cin >> ab[i].second;
  }

  sort(ab.begin(), ab.end());
  vector<int64_t> dp(5001);
  dp[0] = 1;
  int64_t counter = 0;
  for (int64_t i{0}; i < n; ++i) {
    for (int64_t j{5000}; j >= 0; --j) {
      int64_t new_pos = ab[i].second + j;
      if(new_pos <= ab[i].first) {
        counter += dp[j];
        counter %= MOD;
      }
      if(new_pos <= 5000) {
        dp[new_pos] += dp[j];
        dp[new_pos] %= MOD;
      }
    }
  }

  cout << counter % MOD << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  solution();

  return 0;
}
