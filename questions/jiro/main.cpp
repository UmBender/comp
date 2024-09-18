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
  char x, y, z;
  cin >> x >> y >> z;
  if (x == '<' && y == '>') {
    cout << 'A' << endl;
    return;
  }
  if (x == '>' && y == '<') {
    cout << 'A' << endl;
    return;
  }

  if (x == '<' && z == '<') {
    cout << 'B' << endl;
    return;
  }
  if (x == '>' && z == '>') {
    cout << 'B' << endl;
    return;
  }
  cout << 'C' << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solution();

  return 0;
}
