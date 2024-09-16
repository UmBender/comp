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
  int a = 0;
  int b = 0;
  int minus = 0;
  int plus = 0;
  vector<int> arra(n), arrb(n);
  for (auto &i : arra) {
    cin >> i;
  }
  for (auto &i : arrb) {
    cin >> i;
  }
  for (int i = 0; i < n; i++) {
    int x = arra[i], y = arrb[i];
    if (x == 1 && y == 1) {
      plus++;
      continue;
    }
    if (x == -1 && y == -1) {
      minus++;
      continue;
    }
    if (x == 1) {
      a++;
      continue;
    }
    if (y == 1) {
      b++;
      continue;
    }
  }
  if (a < b) {
    swap(a, b);
  }
  // int max_res = a - b;
  // a -= min(max_res, minus);
  // minus -= min(max_res, minus);
  // int new_plus = plus - min(plus, minus);
  // minus -= min(plus, minus);
  // if (new_plus == 0) {
  //   if (minus % 2 == 0) {
  //     a -= minus / 2;
  //   } else {
  //     a -= minus / 2 + 1;
  //   }
  //   cout << min(a, b) << endl;
  // } else {
  //   if (a - b >= new_plus) {
  //     b += new_plus;
  //     cout << min(b, a) << endl;
  //   } else {
  //     new_plus -= (a - b);
  //     b = a;
  //     cout << min(a, b + new_plus / 2) << endl;
  //   }
  // }
  //
  while (plus) {
    if (b > a) {
      swap(b, a);
    }
    b++;
    plus--;
  }
  while (minus) {
    if (b > a) {
      swap(b, a);
    }
    a--;
    minus--;
  }
  cout << min(a, b) << endl;
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
