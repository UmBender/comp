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

void dfs(int actual_node, int last_node, int height,
         vector<pair<int, int>> &dist, vector<vector<int>> &adj) {
  for (auto i : adj[actual_node]) {
    if (i == last_node) {
      continue;
    }
    dist[i - 1].first = height + 1;
    dfs(i, actual_node, height + 1, dist, adj);
  }
}

void solution() {
  int n, st, en;
  cin >> n >> st >> en;
  vector<vector<int>> adj(n + 1);
  vector<pair<int, int>> dist(n);

  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  if (n == 1) {
    cout << 1 << endl;
    return;
  }

  int acc = 1;
  for (auto &[i, j] : dist) {
    i = 0;
    j = acc;
    acc++;
  }
  dfs(en, en, 0, dist, adj);
  dist[en - 1].first = 0;
  sort(dist.rbegin(), dist.rend());
  for (auto [_, j] : dist) {
    cout << j << " ";
  }
  cout << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  atcoder::modint::set_mod(998244353);
  int t;
  cin >> t;
  while (t--)
    solution();

  return 0;
}
