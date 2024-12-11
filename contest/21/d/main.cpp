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

vector<vector<pair<int, int>>> adj;
vector<vector<pair<int, int>>> adjrev;
vector<bool> visited;
vector<int> x;

void bfs(int starting) {
  queue<int> nodes;
  nodes.push(starting);
  while (!nodes.empty()) {
    int now_node = nodes.front();
    nodes.pop();
    for (auto &[i, j] : adj[now_node]) {
      if (!visited[i]) {
        x[i] = j + x[now_node];
        visited[i] = true;
        nodes.push(i);
      }
    }
    for (auto &[i, j] : adjrev[now_node]) {
      if (!visited[i]) {
        x[i] = x[now_node] - j;
        visited[i] = true;
        nodes.push(i);
      }
    }
  }
}

void solution() {
  int n, m;
  cin >> n >> m;
  adj.resize(n + 1);
  adjrev.resize(n + 1);
  visited.resize(n + 1);
  x.resize(n + 1, -1);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back(make_pair(v, w));
    adjrev[v].push_back(make_pair(u, w));
  }
  for (int i = 1; i < visited.size(); i++) {
    if (visited[i]) {
      continue;
    }
    x[i] = 0;
    visited[i] = true;
    bfs(i);
  }
  for (int i = 1; i <= n; i++) {
    cout << x[i] << ' ';
  }
  cout << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solution();

  return 0;
}
