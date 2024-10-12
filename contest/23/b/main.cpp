#include <bits/stdc++.h>
#include <cmath>

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

struct Point {
  long double x;
  long double y;
};

long double dist(Point &i, Point &j) {
  long double x2 = (i.x - j.x) * (i.x - j.x);
  long double y2 = (i.y - j.y) * (i.y - j.y);
  return sqrtl(x2 + y2);
}

void solution() {
  int n;
  cin >> n;
  vector<Point> p(n + 1);
  p[0].x = 0.0f;
  p[0].y = 0.0f;
  for (int i = 1; i <= n; i++) {
    cin >> p[i].x;
    cin >> p[i].y;
  }
  long double disti = 0;
  for (int i = 0; i < n; i++) {
    long double new_dist = dist(p[i + 1], p[i]);
    disti += new_dist;
  }
  disti += dist(p[0], p.back());
  cout << disti << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cout << std::setprecision(std::numeric_limits<long double>::digits10 + 1);
  cout << fixed;
  solution();

  return 0;
}
