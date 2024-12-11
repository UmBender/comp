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

bool eq(string &s, string &k, int begin) {
  for (int i = 0; i < 4; i++) {
    if (i + begin >= s.size() || i + begin < 0) {
      return false;
    }
    if (s[i + begin] != k[i]) {
      return false;
    }
  }
  return true;
}
bool add(string &s, int pos) {
  string k = "1100";
  for (int i = -3; i < 1; i++) {
    if (eq(s, k, i + pos)) {
      return true;
    }
  }
  return false;
}

void solution() {
  string s;
  cin >> s;
  int q;
  cin >> q;
  int counter = 0;
  for (int i = 0; i < s.size() - 3; i++) {
    bool find = false;
    if (s[i] == '1') {
      if (s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0') {
        find = true;
      }
    }
    if (find) {
      counter++;
    }
  }
  while (q--) {
    int i;
    char v;
    cin >> i >> v;
    i--;
    if (s[i] != v) {
      if (add(s, i)) {
        counter--;
      }
      s[i] = v;
      if (add(s, i)) {
        counter++;
      }
    }
    if (counter > 0) {
      cout << "YES" << endl;

    } else {
      cout << "NO" << endl;
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
