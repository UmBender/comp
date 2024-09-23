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
  string w1, w2;
  cin >> w1 >> w2;
  vector<vector<int>> dist(w1.size() + 1, vector<int>(w2.size() + 1, INT_MAX));
  dist[0][0] = 0;
  for (int i = 0; i < dist.size(); i++) {
    for (int j = 0; j < dist[i].size(); j++) {

      if (i > 0) {
        dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
      }
      if (j > 0) {
        dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
      }
      if (i > 0 && j > 0) {
        dist[i][j] =
            min(dist[i][j], dist[i - 1][j - 1] + (w1[i - 1] != w2[j - 1]));
      }
    }
  }
  cout << dist.back().back() << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solution();

  return 0;
}
