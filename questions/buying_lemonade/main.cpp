#include <algorithm>
#include <bits/stdc++.h>
#include <functional>

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
  int n, k;
  cin >> n >> k;
  vector<int> an(n);
  for (auto &i : an) {
    cin >> i;
  }
  stable_sort(an.begin(), an.end());
  int sum = 0;
  int ops = 0;
  int alast = 0;
  for (int i = 0; i < n; i++) {
    int hold_sum = sum + (an[i] - alast) * (n - i);
    if (hold_sum < k) {
      ops += (an[i] - alast) * (n - i) + 1;
      sum = hold_sum;
      alast = an[i];
      continue;
    }
    cout << ops + (k - sum) << endl;
    return;
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
