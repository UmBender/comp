#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl '\n'

#define MAX_INT ((int)1E18 + 1000)

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
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int counter = 0;

  vector<int> dp(2 * n + 10);
  for (int i = 1; i <= n; i++) {
    dp[a[i]] = i;
  }

  for (int i = 1; i <= 2 * n + 10; i++) {
    if (dp[i] == 0) {
      continue;
    }
    for (int j = 1; j * i <= 2 * n; j++) {
      if (dp[j] == 0) {
        continue;
      }
      if (dp[i] < dp[j] && dp[i] + dp[j] == i * j) {
        // cout << "A[i] = " << i << " i = " << dp[i] << " A[j] = " << j
        //      << " j = " << dp[j] << endl;
        counter++;
      }
    }
  }

  std::cout << counter << endl;
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
