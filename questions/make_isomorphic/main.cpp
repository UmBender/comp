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

vector<vector<int>> g(9, vector<int>(9, 0));
vector<vector<int>> h(9, vector<int>(9, 0));
vector<vector<int>> adj(9, vector<int>(9, 0));

void solution() {
  int n, mg, mh;
  cin >> n >> mg;
  for (int i = 0; i < mg; i++) {
    int u, v;
    cin >> u >> v;
    g[u][v] = 1;
    g[v][u] = 1;
  }

  cin >> mh;
  for (int i = 0; i < mh; i++) {
    int u, v;
    cin >> u >> v;
    h[u][v] = 1;
    h[v][u] = 1;
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      cin >> adj[i + 1][j + 1];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) {
        adj[i][j] = 0;
      }
      adj[j][i] = adj[i][j];
    }
  }
  vector<int> order;
  for (int i = 1; i <= n; i++) {
    order.push_back(i);
  }

  int min_cost = 0x3f3f3f3f;
  do {
    int cost = 0;
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        if (h[order[i]][order[j]] == g[i + 1][j + 1]) {

        } else {
          cost += adj[order[i]][order[j]];
        }
      }
    }

    min_cost = min(min_cost, cost);

  } while (next_permutation(order.begin(), order.end()));
  cout << min_cost << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solution();
  return 0;
}
