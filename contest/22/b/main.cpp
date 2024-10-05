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
  string s, t;
  cin >> s >> t;
  if (s != t) {
    if (s.size() != t.size()) {
      if (s.size() > t.size()) {
        swap(s, t);
      }
      for (int i = 0; i < s.size(); i++) {
        if (s[i] != t[i]) {
          cout << i + 1 << endl;
          return;
        }
      }
      cout << s.size() + 1 << endl;

    } else {
      for (int i = 0; i < s.size(); i++) {
        if (s[i] != t[i]) {
          cout << i + 1 << endl;
          return;
        }
      }
    }

  } else {
    cout << "0" << endl;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solution();

  return 0;
}
