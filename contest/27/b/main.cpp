#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll

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
  if (n == 1) {
    cout << 1 << endl;
    return;
  }
  if (n == 2) {
    cout << a[1] - a[0] << endl;
    return;
  }
  if (n % 2 == 0) {
    int max = -1;
    for (int i = 0; i < n - 1; i += 2) {
      if (a[i + 1] - a[i] > max) {
        max = a[i + 1] - a[i];
      }
    }
    cout << max << endl;
    return;
  }
  int minimal = (int)1E18 + 1000;

  for (int i = 0; i < n; i += 2) {
    int firstmax = 1;
    for (int j = 0; j < i && j < n - 1; j += 2) {
      if (a[j + 1] - a[j] > firstmax) {
        firstmax = a[j + 1] - a[j];
      }
    }
    for (int j = i + 1; j < n - 1; j += 2) {
      if (a[j + 1] - a[j] > firstmax) {
        firstmax = a[j + 1] - a[j];
      }
    }
    if (firstmax < minimal) {
      minimal = firstmax;
    }
  }
  cout << minimal << endl;
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
