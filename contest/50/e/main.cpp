#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
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

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll
using mint = atcoder::modint;

vector<int> dijkstra(vector<map<int, int>> &graph, int source) {
  int n = graph.size();
  vector<int> dist(n, MAX_INT);
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  dist[source] = 0;
  pq.push({0, source});

  while (!pq.empty()) {
    int d = pq.top().first;
    int u = pq.top().second;
    pq.pop();

    if (d > dist[u])
      continue;

    for (const auto &[v, cost] : graph[u]) {
      if (dist[u] + cost < dist[v]) {
        dist[v] = dist[u] + cost;
        pq.push({dist[v], v});
      }
    }
  }
  return dist;
}

void solution() {
  int n, m, x;
  cin >> n >> m >> x;
  vector<map<int, int>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u][v] = 1;
    if (adj[v].count(u) == 0) {
      adj[v][u] = x;
    }
  }
  auto dists = dijkstra(adj, 1);
  cout << dists[n] << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  atcoder::modint::set_mod(998244353);
  solution();

  return 0;
}
