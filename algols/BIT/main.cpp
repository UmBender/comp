#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl '\n'

#define MAX_INT ((int)1E18 + 1000)

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

struct BIT {
  vector<int> bit;
  int n;
  BIT(int n) {
    this->n = n;
    bit.assign(n, 0);
  }
  BIT(vector<int> const &a) : BIT(a.size()) {
    for (size_t i = 0; i < a.size(); i++) {
      add(i, a[i]);
    }
  }

  int sum(int r) {
    int ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) {
      ret += bit[r];
    }
    return ret;
  }
  int sum(int l, int r) { return sum(r) - sum(l - 1); }
  void add(int idx, int delta) {
    for (; idx < n; idx = idx | (idx + 1)) {
      bit[idx] += delta;
    }
  }
};
void solution() {
  ;
  ;
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
