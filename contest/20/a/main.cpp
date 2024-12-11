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
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  int max_pos = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > a[max_pos]) {
      max_pos = i;
    }
    if (a[i] >= a[max_pos] && (i + 1) % 2) {
      max_pos = i;
    }
  }

  if ((n) % 2) {
    if ((max_pos + 1) % 2) {
      cout << a[max_pos] + (n + 1) / 2 << endl;
    } else {
      cout << a[max_pos] + n / 2 << endl;
    }
  } else {
    cout << a[max_pos] + n / 2 << endl;
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
