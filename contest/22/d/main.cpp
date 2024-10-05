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
  int a, b, c, d;
};

double dist_first(Point p, int a, int b) {
  return sqrt(((long double)p.a - (long double)a) *
                  ((long double)p.a - (long double)a) +
              ((long double)p.b - (long double)b) *
                  ((long double)p.b - (long double)b)) +
         sqrt(((long double)p.c - (long double)p.a) *
                  ((long double)p.c - (long double)p.a) +
              ((long double)p.d - (long double)p.b) *
                  ((long double)p.d - (long double)p.b));
}
double dist_second(Point p, int a, int b) {}

long double rec_dist(int i, int actual_a, int actual_b, vector<Point> &p,
                     long double acc) {
  if (i >= p.size()) {
    return acc;
  }
  long double first = acc + sqrt((p.front().a - actual_a))
}

void solution() {
  int n, t, s;
  cin >> n >> s >> t;
  vector<Point> point(n);
  for (int i{0}; i < n; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    Point p = Point{
        a = a,
        b = b,
        c = c,
        d = d,
    };
    point[i] = p;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solution();

  return 0;
}
