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
  int m;
  cin >> m;
  int power3 = 1;
  int exp = 0;
  vector<int> vx;
  while (power3 * 3 <= m && exp < 10) {
    power3 *= 3;
    exp++;
  }

  while (m) {
    if (power3 <= m) {
      vx.push_back(exp);
      m -= power3;
    } else {
      power3 /= 3;
      exp--;
    }
  }
  cout << vx.size() << endl;
  for (auto i : vx) {
    cout << i << ' ';
  }
  cout << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solution();

  return 0;
}
