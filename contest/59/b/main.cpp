// clang-format off
//#include <atcoder/all>
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
//using mint = atcoder::modint;
// clang-format on

void solution() {
  int n;
  cin >> n;
  string aa;
  string bb;
  vector<bool> a(n), b(n);
  cin >> aa >> bb;
  for (int i = 0; i < n; i++) {
    a[i] = aa[i] == '1';
    b[i] = bb[i] == '1';
  }
  int counter_even = 0;
  int counter_odd = 0;
  for (int i = 0; i < n; i++) {
    if ((i & 1) == 0 && a[i]) {
      counter_even++;
    }
    if ((i & 1) == 1 && a[i]) {
      counter_odd++;
    }
    if ((i & 1) == 0 && b[i]) {
      counter_odd++;
    }
    if ((i & 1) == 1 && b[i]) {
      counter_even++;
    }
  }

  if (n / 2 < counter_even || (n + 1) / 2 < counter_odd) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
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
