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

vector<int> a;
int total;
int n, k;

void solution() {
  cin >> n >> k;
  a.resize(n);
  total = 0;
  for (auto &i : a) {
    cin >> i;
    total += i;
  }
  sort(a.begin(), a.end());
  int max_divisor = min(n, (total + k) / a.back());
  for (int i = max_divisor; i >= 1; i--) {
    if ((total + k) % i <= k) {
      cout << i << endl;
      return;
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
