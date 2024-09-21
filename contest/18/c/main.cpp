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
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  n--;
  int counter = 0;
  string abc = "ABC";
  for (int i = 0; i <= n - 2; i++) {
    if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C') {
      counter++;
    }
  }
  for (int i = 0; i < q; i++) {

    int x;
    char c;
    cin >> x >> c;
    x--;

    switch (s[x]) {
    case 'A':
      if (x + 2 <= n) {
        counter -= s[x + 1] == 'B' && s[x + 2] == 'C';
      }
      break;
    case 'B':
      if (x + 1 <= n && x - 1 >= 0) {
        counter -= s[x - 1] == 'A' && s[x + 1] == 'C';
      }
      break;
    case 'C':
      if (x - 2 >= 0) {
        counter -= s[x - 2] == 'A' && s[x - 1] == 'B';
      }
      break;
    default:
      break;
    }
    switch (c) {
    case 'A':
      if (x + 2 <= n) {
        counter += s[x + 1] == 'B' && s[x + 2] == 'C';
      }
      break;
    case 'B':
      if (x - 1 >= 0 && x + 1 <= n) {
        counter += s[x - 1] == 'A' && s[x + 1] == 'C';
      }
      break;
    case 'C':
      if (x - 2 >= 0) {
        counter += s[x - 2] == 'A' && s[x - 1] == 'B';
      }
      break;
    default:
      break;
    }
    s[x] = c;
    cout << counter << endl;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solution();

  return 0;
}
