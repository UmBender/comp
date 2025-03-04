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

void solution() {
  int k;
  cin >> k;
  vector<int> a(k + 1);
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    a[x]++;
  }
  int target = k - 2;
  int m, n;
  for (int i = 1; i <= k; i++) {
    if (a[i] <= 0) {
      continue;
    }
    a[i]--;
    if (target % i == 0) {
      int value = target / i;
      if (a[value] > 0) {
        n = value;
        m = i;
        break;
      }
    }
    a[i]--;
  }
  cout << m << " " << n << endl;
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
