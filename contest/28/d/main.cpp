#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>

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

bool eq(string &s, int pos) {
  string caps = "1543";
  if (pos + 3 >= s.size()) {
    return false;
  }
  for (int i = 0; i < 4; i++) {
    if (s[i + pos] != caps[i]) {
      return false;
    }
  }
  return true;
}
void solution() {
  int n, m;
  cin >> n >> m;
  vector<string> carpet(n);
  string caps = "1543";
  for (int i = 0; i < n; i++) {
    cin >> carpet[i];
  }
  int level = min(n, m) / 2;
  vector<string> levels(level);
  for (int i = 0; i < level; i++) {
    string acc = "";
    for (int j = i; j < m - i; j++) {
      acc.push_back(carpet[i][j]);
    }
    for (int j = i + 1; j < n - i; j++) {
      acc.push_back(carpet[j][m - i - 1]);
    }
    for (int j = m - i - 2; j >= i; j--) {
      acc.push_back(carpet[n - i - 1][j]);
    }
    for (int j = n - i - 2; j >= i + 1; j--) {
      acc.push_back(carpet[j][i]);
    }
    for (int i = 0; i < 3; i++) {
      acc.push_back(acc[i]);
    }
    levels[i] = acc;
  }
  int counter = 0;

  for (int i = 0; i < level; i++) {
    for (int j = 0; j < levels[i].size() - 3; j++) {
      if (eq(levels[i], j)) {
        counter++;
      }
    }
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
