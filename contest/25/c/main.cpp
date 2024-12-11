#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

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

int solve(unordered_map<int, vector<int>> &m, unordered_map<int, int> &calc,
          int k) {
  int maxx = 0;
  for (int i = 0; i < m[k].size(); i++) {
    int val;
    if (calc.count(k + m[k][i])) {
      val = calc[k + m[k][i]] + m[k][i];
    } else {
      val = solve(m, calc, k + m[k][i]) + m[k][i];
    }
    if (val > maxx) {
      maxx = val;
    }
  }
  calc[k] = maxx;
  return maxx;
}

void solution() {
  int n;
  cin >> n;
  unordered_map<int, vector<int>> m;
  unordered_map<int, int> calculated;

  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    if (val + i - n >= 0 && i != 0) {
      if (m.count(val + i - n)) {
        m[val + i - n].push_back(i);
      } else {
        m[val + i - n] = {i};
      }
    }
  }
  cout << solve(m, calculated, 0) + n << endl;
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
