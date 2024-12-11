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

int pow2(int a) { return a * a; }
int dist(pair<int, int> a, pair<int, int> b) {
  return pow2(b.first - a.first) + pow2(b.second - a.second);
}

void solution() {
  int x, y, k;
  cin >> x >> y >> k;
  pair<int, int> bp1;
  pair<int, int> ep1;
  pair<int, int> bp2;
  pair<int, int> ep2;
  bool find = false;
  if (x >= y) {
    bp1 = make_pair(0, y);
    ep1 = make_pair(y, y);
    bp2 = make_pair(0, 0);
    ep2 = make_pair(0, y);
    while (!find) {
      if (dist(bp1, ep1) >= pow2(k) && dist(bp2, ep2) >= pow2(k)) {
        find = true;
      } else {
        ep1.second--;
        ep2.first++;
      }
    }
  } else {
    bp1 = make_pair(0, x);
    ep1 = make_pair(x, x);
    bp2 = make_pair(0, 0);
    ep2 = make_pair(0, x);
    while (!find) {
      if (dist(bp1, ep1) >= pow2(k) && dist(bp2, ep2) >= pow2(k)) {
        find = true;
      } else {
        ep1.second--;
        ep2.first++;
      }
    }
  }
  cout << bp1.first << ' ' << bp1.second << ' ' << ep1.first << ' '
       << ep1.second << endl;
  cout << bp2.first << ' ' << bp2.second << ' ' << ep2.first << ' '
       << ep2.second << endl;
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
