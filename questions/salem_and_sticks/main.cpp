#include <atcoder/all>
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
using mint = atcoder::modint;

void solution() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  int min_cost = MAX_INT;
  int min_i = 0;

  for (int i = 1; i < 100; i++) {
    int actual_cost = 0;
    for (int j = 0; j < n; j++) {
      if (a[j] > i) {
        actual_cost += min(abs(a[j] - i), abs(a[j] - (i + 1)));

      } else {
        actual_cost += min(abs(a[j] - i), abs(a[j] - (i - 1)));
      }
    }
    if (actual_cost < min_cost) {
      min_cost = actual_cost;
      min_i = i;
    }
  }
  cout << min_i << " " << min_cost << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  atcoder::modint::set_mod(998244353);
  solution();

  return 0;
}
