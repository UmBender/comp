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
  string ss;
  cin >> ss;
  vector<int> s(n);
  for (int i = 0; i < n; i++) {
    if (ss[i] == '0') {
      s[i] = 0;
    } else {
      s[i] = 1;
    }
  }
  int num_val = -1;
  int longest = 0;
  int counter = 0;
  int power_of_two = 1LL;

  for (int i = 0; i < n; i++) {
    if (num_val != s[i]) {
      num_val = s[i];
      longest = 0;
      power_of_two = 1LL;
    } else {
      longest++;
      power_of_two = power_of_two << 1;
    }
    power_of_two %= mod;
    counter += power_of_two;
    counter %= mod;
  }
  cout << counter << endl;
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
