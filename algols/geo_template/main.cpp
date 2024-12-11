#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

typedef double T;
typedef complex<T> pt;

pt scale(pt c, double factor, pt p) { return c + (p - c) * factor; }
pt rot(pt p, double a) { return p * polar(1.0, a); }

struct line {
  pt v;
  T c;
  line(pt v, T c) : v(v), c(c) {}
  line(T a, T b, T c) : v(complex(b, -a)), c(c) {}

  T side(pt p);
  double dist(pt p);
  line perpThrough(pt p);
  bool cmpProj(pt p, pt q);
  line translate(pt t);
  void shiftLeft(double dist);
  pt proj(pt p);
  pt refl(pt p);
};

int32_t main() {
  pt a = complex(1.0, 3.0);
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cout << "Hello World" << endl;
  cout << rot(a, 2 * 3.14) << endl;
  cout << a * a << endl;

  return 0;
}
