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
  int n, k, p;
  cin >> n >> k >> p;

  if (k < 0) {
    int val_iter = -p;
    if (val_iter * n > k) {
      cout << -1 << endl;
      return;
    }
    int acc = 0;
    int counter = 0;
    while(acc > k) {
      acc += val_iter;
      counter ++;
    }
    cout << counter << endl;
  } else {
    int val_iter = p;
    if (val_iter * n < k) {
      cout << -1 << endl;
      return;
    }
    int acc = 0;
    int counter = 0;
    while(acc < k) {
      acc += val_iter;
      counter++;
    }
    cout << counter<< endl;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  atcoder::modint::set_mod(998244353);
  int t;
  cin >> t;
  while (t--)
    solution();

  return 0;
}
