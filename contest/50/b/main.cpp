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
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int ii = 0;
      if (i >= n / 2) {
        ii = n - i - 1;
      } else {
        ii = i;
      }
      int jj = 0;
      if (j >= n / 2) {
        jj = n - j - 1;
      } else {
        jj = j;
      };
      cout << ((min(ii,jj) % 2 == 0) ? '#':'.');
      a[i][j] = min(ii, jj);
    }
    cout << endl;
  }
  return;
  for (auto &i : a) {
    for (int j = 0; j < n; j++) {
      cout << i[j] << " \n"[j == n - 1];
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  atcoder::modint::set_mod(998244353);
  solution();

  return 0;
}
