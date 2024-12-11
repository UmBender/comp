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

void bfs(vector<vector<int>> &adj, int s, vector<bool> &visited) {
  queue<int> q;
  visited[s] = true;
  q.push(s);

  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    cout << curr << " ";

    for (int x : adj[curr]) {
      if (!visited[x]) {
        visited[x] = true;
        q.push(x);
      }
    }
  }
}

void addEdge(vector<vector<int>> &adj, int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

void bfsDisconnected(vector<vector<int>> &adj) {
  vector<bool> visited(adj.size(), false);
  for (int i = 0; i < visited.size(); i++) {
    if (!visited[i]) {
      bfs(adj, i, visited);
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int V = 6;
  vector<vector<int>> adj(V);

  addEdge(adj, 0, 1);
  addEdge(adj, 0, 2);
  addEdge(adj, 3, 4);
  addEdge(adj, 4, 5);

  bfsDisconnected(adj);

  return 0;
}
