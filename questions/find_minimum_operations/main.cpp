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

int find_max(int n, int k) {
  if (k == 1) {
    return 1;
  }
  int last = 1;
  int actual = k;
  while (actual <= n) {
    last = actual;
    actual *= k;
  }
  return last;
}

void solution() {
  int n, k;
  cin >> n >> k;
  int ops = 0;
  while (n) {
    int sub = find_max(n, k);
    int n_ops = n / sub;
    n -= sub * n_ops;
    ops += n_ops;
  }
  cout << ops << endl;
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
