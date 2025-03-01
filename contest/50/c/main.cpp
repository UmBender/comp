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
  map<int, int> valuepos;
  for (auto &i : a) {
    cin >> i;
  }
  int minn_dist = MAX_INT;
  for (int i = 0; i < n; i++) {
    if (valuepos.count(a[i]) == 0) {
      valuepos[a[i]] = i;
    } else {
      minn_dist = min(minn_dist, i - valuepos[a[i]] + 1);
      valuepos[a[i]] = i;
    }
  }
  if (minn_dist == MAX_INT) {
    cout << -1 << endl;
    return;
  }
  cout << minn_dist << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  atcoder::modint::set_mod(998244353);
  solution();

  return 0;
}
