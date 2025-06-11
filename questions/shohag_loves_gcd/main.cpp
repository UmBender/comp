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
  int m, n;
  cin >> n >> m;
  vector<int> s(m);
  for (auto &i : s) {
    cin >> i;
  }

  if (m == 1 && n == 1) {
    cout << s[0] << endl;
  }

  if (m == 2 && (s[0] == 1 || s[1] == 1)) {
    cout << -1 << endl;
  }
  sort(s.rbegin(), s.rend());
  vector<int> sol(m);
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
