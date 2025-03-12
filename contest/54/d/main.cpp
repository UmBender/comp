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

int dis_sqrt(int x) {
  int l = 0;
  int r = 1E6;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (m * m <= x && ((m + 1) * (m + 1)) > x) {
      return m;
    }
    if (m * m > x) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  return l;
}

int to_pow(int x) { return x * x; }

void solution() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> xr(n);
  for (auto &i : xr) {
    cin >> i.first;
  }
  for (auto &i : xr) {
    cin >> i.second;
  }
  sort(xr.begin(), xr.end());
  map<int, int> max_height;
  for (int i = 0; i < n; i++) {
    for (int j = xr[i].first - xr[i].second; j <= xr[i].first + xr[i].second;
         j++) {
      max_height[j] = max(max_height[j], 2 * dis_sqrt(to_pow(xr[i].second) -
                                                      to_pow(j - xr[i].first)) + 1);
    }
  }
  int counter = 0;
  for(auto &[i,j]: max_height) {
//    dbg(i,j);
    counter+= j;
  }
  cout << counter << endl;
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
