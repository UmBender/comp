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

void solution() {
  int n, k;
  cin >> n >> k;
  map<int, int> bottles;
  vector<pair<int, int>> rev;
  for (int i = 0; i < k; i++) {
    int l, m;
    cin >> l >> m;
    if (!bottles.count(l)) {
      bottles[l] = m;

    } else {
      bottles[l] += m;
    }
  }
  for (auto &[i, j] : bottles) {
    rev.push_back(make_pair(j, i));
  }
  stable_sort(rev.rbegin(), rev.rend());
  int sum = 0;
  for (int i = 0; i < rev.size() && i < n; i++) {
    sum += rev[i].first;
  }
  cout << sum << endl;
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
