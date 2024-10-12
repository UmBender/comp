#include <algorithm>
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
  string s;
  cin >> s;
  map<char, vector<int>> let;
  for (int i = 0; i < s.size(); i++) {
    let[s[i]].push_back(i);
  }
  int counter = 0;
  for (int i = 0; i < s.size(); i++) {
    auto pos = lower_bound(let[s[i]].begin(), let[s[i]].end(), i + 2);
    if (pos == let[s[i]].end()) {
      continue;
    }

    for_each(pos, let[s[i]].end(), [&](auto x) { counter += x - i - 1; });
  }
  cout << counter << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solution();

  return 0;
}
