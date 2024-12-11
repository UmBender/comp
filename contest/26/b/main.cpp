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

int rec(int actual, int rest) {
  if (rest == 0) {
    return actual % 66 == 0 ? actual : -1;
  }

  int first = rec(actual * 10 + 3, rest - 1);
  int second = rec(actual * 10 + 6, rest - 1);
  if (first != -1 && second != -1) {
    return min(first, second);
  }
  if (first == -1 && second == -1) {
    return -1;
  }
  if (first == -1) {
    return second;
  }

  return first;
}
void solution() { int n; }

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
