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
  vector<int> a(n);
  int x = 0;
  map<int, vector<int>> counter;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    counter[a[i]].push_back(i);
  }
  vector<int> dp(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1];
    if (dp[i - 1] < a[i - 1]) {
      dp[i]++;
    }
    if (dp[i - 1] > a[i - 1]) {
      dp[i]--;
    }
  }
  for (auto i : dp) {
    cout << i << ' ';
  }
  cout << endl;
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
