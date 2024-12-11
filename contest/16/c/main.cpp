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

const int mod = 998244353;

void solution() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int count = 0;
  int biggest = 1;
  int actual = 1;
  int pow = 1LL;
  vector<int> a(n);
  a[0] = 1;
  for (int i = 1; i < n; i++) {
    if (a[i] == a[i - 1]) {
      actual++;
      if (biggest < actual) {
        biggest = max(actual, biggest);
        pow = pow << 1;
      }
    } else {
      actual = 1;
    }
    a[i] = pow % mod;
    cout << pow << endl;
  }
  for (auto i : a) {
    count += i;
    count %= mod;
  }
  cout << count << endl;
  cout << endl;
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
