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

void gen_interval(int l, int r, int begin, int end, vector<int> &sizes) {

  if (l > r) {
    return;
  }

  if (begin <= l && r <= end) {
    sizes.push_back(r - l);
    return;
  }

  int m = (r + l) / 2;
  if (m > begin)
    gen_interval(l, m, begin, end, sizes);
  if (m < end)
    gen_interval(m, r, begin, end, sizes);
}

void solution() {
  int l1, r1, l2, r2;
  cin >> l1 >> r1 >> l2 >> r2;
  vector<int> first, second;
  gen_interval(0, 1048576, l1, r1, first);
  gen_interval(0, 1048576, l2, r2, second);
  int counter = 0;
  for (int i : first) {
    for (int j : second) {
      counter += max(i, j) / min(i, j);
    }
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
