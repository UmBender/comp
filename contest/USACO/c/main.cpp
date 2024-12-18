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
  int n, f;
  cin >> n >> f;
  string s;
  cin >> s;
  map<string, int> counting;
  for (int i = 0; i < n - 2; i++) {
    if (s[i] != s[i + 1] && s[i + 1] == s[i + 1]) {
      counting[s.substr(i, i + 3)]++;
    }
  }
  set<string> words;
  for (auto [i, j] : counting) {
    if (j == f || j == f + 1) {
      words.insert(i);
    }
  }
  for (int i = 0; i < n - 2; i++) {
    string soup = "   ";
    if (s[i + 1] == s[i + 2]) {
      for (char j = 'a'; j <= 'z'; j++) {
        if (j == s[i])
          continue;
        soup[0] = j;
        soup[1] = s[1 + i];
        soup[2] = s[2 + i];
        if (soup[0] == soup[1]) {
          continue;
        }

        if (counting[soup] == f - 1) {

          cerr << soup << endl;
        }
        if (counting[soup] + 1 == f) {
          words.insert(soup);
        }
      }
    }
    if (s[i] != s[i + 1] && s[i + 1] != s[i + 2]) {
      if (s[i + 2] == s[i] && i + 4 < n && s[i + 2] == s[i] &&
          s[i + 3] == s[i + 1] && s[i + 4] == s[i + 1]) {
      } else {
        soup[0] = s[i];
        soup[1] = s[i + 1];
        soup[2] = s[i + 1];
        if (counting[soup] + 1 == f) {
          words.insert(soup);
        }
      }
    }
  }

  cout << words.size() << endl;
  for (auto i : words) {
    cout << i << endl;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solution();

  return 0;
}
