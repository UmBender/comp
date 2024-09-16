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

int gcd(int a, int b) {
  if (a == 0)
    return b;
  return gcd(b % a, a);
}
void solution() {
  int n, a, b;

  cin >> n >> a >> b;
  vector<int> d(n);
  for (auto &i : d) {
    cin >> i;
  }
  int vgcd = __gcd(a, b);
  for (int i = 0; i < n; i++) {
    d[i] %= vgcd;
  }
  sort(d.begin(), d.end());
  int min_dist = d.back() - d.front();
  int max_value = d.back();

  for (int i = 0; i < n - 1; i++) {
    if (max_value - d[i] >= d[i] + vgcd - max_value) {
      min_dist = min(min_dist, d[i] + vgcd - d[i + 1]);
      max_value = d[i] + vgcd;
    } else {
      min_dist = max_value - d[i];
      break;
    }
  }
  cout << min_dist << endl;
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
