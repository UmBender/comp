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

void solution() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, vector<int>> caps;
  for (auto &i : a) {
    cin >> i;
  }
  int minimal = INT_MAX;
  vector<int> pos_minimal;
  for (int i = 0; i < n; i++) {
    caps[a[i]].push_back(i);
    if (a[i] < minimal) {
      minimal = a[i];
      pos_minimal.clear();
      pos_minimal.push_back(i);
    }
    if (a[i] == minimal) {
      pos_minimal.push_back(i);
    }
  }
  vector<int> dp(n);
  for (auto k : (*caps.begin()).second) {
    int i = k, j = k;
    while (i >= 0 && j < n) {
    }
  }
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
