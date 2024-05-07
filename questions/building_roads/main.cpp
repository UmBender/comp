#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10
#define ii pair<ii>
#define f first
#define l last

int color[100010] = {-1};
vector<vector<int>> adj(100010);
vector<int> jumps;

int n, m;

void dfs(int node, int c) {
  for (int i = 0; i < adj[node].size(); i++) {
    if (color[adj[node][i]] == -1) {
      color[adj[node][i]] = c;
      dfs(adj[node][i], c);
    }
  }
}

void solution() {
  for (int i = 0; i < n; i++) {
    if (color[i] == -1) {
      color[i] = i;
      jumps.push_back(i);
      dfs(i, i);
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;

    adj[a-1].push_back(b-1);
    adj[b-1].push_back(a-1);
  }
  for (int i = 0; i < n; i++) {
    color[i] = -1;
  }
  solution();
  cout << jumps.size() - 1 << endl;

  for (int i = 1; i < jumps.size(); i++) {
    cout << jumps[i - 1] + 1 << " " << jumps[i] + 1 << endl;
  }

  return 0;
}
