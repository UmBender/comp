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

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> k;
  for (auto &i : a) {
    cin >> i;
  }

  int counter = 0;
  for (int i = 0; i < n; i++) {
    int t = k.count(a[i]);
    if (!t) {
      k[a[i]] = i;
      counter += (i + 1) * (n - i);
    } else {
      int j = k[a[i]];
      k[a[i]] = i;
      counter += (i - j) * (n - i);
    }
  }
  cout << counter << endl;

  return 0;
}
