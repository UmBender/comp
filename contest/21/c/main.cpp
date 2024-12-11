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
  int max_a = ((int)-1E9) - 100;
  int max_b = ((int)-1E9) - 100;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    max_a = max(a, max_a);
  }

  for (int i = 0; i < n; i++) {
    int b;
    cin >> b;
    max_b = max(b, max_b);
  }
  cout << max_b + max_a << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solution();

  return 0;
}
