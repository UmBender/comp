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
  int n, k;
  cin >> n >> k;
  int caps = (k + 1) / 2;
  int rest = k - caps;
  if (n % 2) {
    if (caps % 2) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  } else {
    if (rest % 2) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
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
