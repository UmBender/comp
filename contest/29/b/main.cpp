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
  int n;
  cin >> n;
  string s, r;
  cin >> s >> r;
  int sone{0}, szero{0};
  for (auto i : s) {
    if (i == '1')
      sone++;
    else
      szero++;
  }
  for (int i = 0; i < r.size(); i++) {
    if (sone == 0 || szero == 0) {
      cout << "NO" << endl;
      return;
    }
    sone--;
    szero--;
    if (r[i] == '1')
      sone++;
    else
      szero++;
  }
  cout << "YES" << endl;
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