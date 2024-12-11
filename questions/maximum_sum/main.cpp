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

const int mod = 1E9 + 7;
void solution() {
  int n, t;
  cin >> n >> t;
  int all_sum{0};
  vector<int> arr(n);
  for (auto &i : arr) {
    cin >> i;
  }
  int max_val = arr[0];
  int value = arr[0];
  for (int i = 1; i < n; i++) {
    value += arr[i];
    if (value < 0) {
      value = 0;
    }
    max_val = max(value, max_val);
  }
  int sum = max_val;
  while (t--) {
    sum += sum;
    sum %= mod;
  }
  cout << sum << endl;
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
