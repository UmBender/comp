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
  vector<int> arr(n);
  vector<int> dp(n);
  // vector<vector<int>> dp(n, vector<int>(n));
  for (auto &i : arr) {
    cin >> i;
  }
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < i; j++) {
  //     if (j == 0) {
  //       dp[i][j] = arr[i] > arr[j] ? 1 : 0;
  //     } else {
  //       dp[i][j] = dp[i][j - 1] + arr[i] > arr[j] ? 1 : 0;
  //     }
  //   }
  //   for (int j = n - 1; j > i; j--) {
  //     if (j == n - 1) {
  //       dp[i][j] = arr[i] < arr[j] ? 1 : 0;
  //     } else {
  //       dp[i][j] = dp[i][j + 1] + arr[i] < arr[j] ? 1 : 0;
  //     }
  //   }
  // }
  int minn = INT_MAX;
  for (int i = 0; i < n; i++) {
    dp[i] = i;

    for (int j = i + 1; j < n; j++) {
      dp[i] += arr[i] < arr[j] ? 1 : 0;
    }
    minn = min(minn, dp[i]);
  }
  cout << minn << endl;
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
