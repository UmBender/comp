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

vector<vector<int>> adj(100010);
vector<int> visited(100010, -1);

int dfs(int node) {
  if (visited[node] == -1) {
    int maxx = 0;
    for (auto i : adj[node]) {
      maxx = max(dfs(i) + 1, maxx);
    }
    visited[node] = maxx;
  }
  return visited[node];
}

void solution() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
  }
  int maxx = 0;
  for (int i = 1; i <= n; i++) {
    if (visited[i] == -1) {
      visited[i] = dfs(i);
    }
    maxx = max(visited[i], maxx);
  }
  cout << maxx << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solution();

  return 0;
}
