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

map<tuple<int, int, int, int>, int> values;

int count_regions(int l1, int r1, int l2, int r2) {
  if (values.count({l1, r1, l2, r2})) {

    return values[{l1, r1, l2, r2}];
  }
  int max_region = 1;
  while (r1 > max_region || r2 > max_region) {
    max_region *= 2;
  }
  if (l1 == 0 && l2 == 0 && r1 == max_region && r2 == max_region) {
    values[{l1, r1, l2, r2}] = 1;
    return values[{l1, r1, l2, r2}];
  }

  if (l1 == max_region / 2 && r1 == max_region && l2 == max_region / 2 &&
      r2 == max_region) {
    values[{l1, r1, l2, r2}] = 1;
    return values[{l1, r1, l2, r2}];
  }
  vector<pair<int, int>> x;
  vector<pair<int, int>> y;
  if (l1 < max_region / 2) {
    x.push_back({l1, min(max_region / 2, r1)});
  }
  if (r1 > max_region / 2) {
    x.push_back({0, r1 - max_region / 2});
  }
  if (l2 < max_region / 2) {
    y.push_back({l2, min(max_region / 2, r2)});
  }
  if (r2 > max_region / 2) {
    y.push_back({0, r2 - max_region / 2});
  }
  int counter = 0;
  for (auto xi : x) {
    for (auto yi : y) {
      counter += count_regions(xi.first, xi.second, yi.first, yi.second);
    }
  }
  values[{l1, r1, l2, r2}] = counter;
  return values[{l1, r1, l2, r2}];
}

void solution() {
  int l1, r1, l2, r2;
  cin >> l1 >> r1 >> l2 >> r2;
  cout << count_regions(l1, r1, l2, r2) << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  // atcoder::modint::set_mod(998244353);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      values[{i, i + 1, j, j + 1}] = 1;
    }
  }
  int t;
  cin >> t;
  while (t--)
    solution();

  return 0;
}
