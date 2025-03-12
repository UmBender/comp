// #include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
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

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll
// using mint = atcoder::modint;

bool check(int x, int y) {

  return ((x ^ y) < x + y) && (x < (x ^ y) + y) && (y < x + (x ^ y));
}
void solution() {
  int x;
  cin >> x;
  if (x <= 4) {
    cout << -1 << endl;
    return;
  }
  int counter = 0;
  vector<bool> xb(64);
  vector<bool> yb(64);
  int oldx = x;
  for (int i = 0; i < 64; i++) {
    if (x & 1) {
      counter++;
    }
    xb[i] = (x & 1);
    x /= 2;
  }

  if (counter < 2) {
    cout << -1 << endl;
    return;
  }

  bool finded = false;
  int first_one = 0;
  int ones = 0;
  int zeros = 0;
  for (int i = xb.size() - 1; i >= 0; i--) {
    if (!finded) {
      if (xb[i]) {
        first_one = i;
        finded = true;
      }
    } else {
      if (xb[i]) {
        ones++;
      } else {
        zeros++;
      }
    }
  }

  if (ones == 0 || zeros == 0) {
    cout << -1 << endl;
    return;
  }

  if (xb[first_one - 1]) {
    yb[first_one] = true;
    for (int i = first_one - 1; i >= 0; i--) {
      yb[i] = !xb[i];
    }
  } else {
    bool one_equal = false;
    for (int i = first_one - 1; i >= 0; i--) {
      if (xb[i] == true && !one_equal) {
        yb[i] = true;
      } else {
        yb[i] = !xb[i];
      }
    }
  }

  int y = 0;
  for (int i = yb.size() - 1; i >= 0; i--) {
    y *= 2;
    y += yb[i];
  }
  cout << y << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  // atcoder::modint::set_mod(998244353);
  int t;
  cin >> t;
  while (t--)
    solution();

  return 0;
}
