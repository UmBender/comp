#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll

void dfs(vector<vector<int>> &adj, vector<int> &values, int actual_node) {
  int acc = 0;
  for (auto i : adj[actual_node]) {
    dfs(adj, values, i);
    acc += values[i] + 1;
  }
  values[actual_node] = acc;
}

void solution() {
  int n;
  cin >> n;
  vector<int> caps(n - 1);
  for (auto &i : caps) {
    cin >> i;
  }
  vector<vector<int>> adj(n + 1);
  for (int i = 1; i < n; i++) {
    adj[caps[i - 1]].push_back(i + 1);
  }

  vector<int> values(n+1, -1);
  dfs(adj, values, 1);
  for(int i = 1; i <= n; i++) {
    cout << values[i] << " \n"[i==n];
  }

}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  solution();

  return 0;
}
