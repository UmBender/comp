#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

int n, m;
vector<vector<int>> adj(100010);
vector<bool> visited(100010, false);
vector<int> before(100010, -1);

void bfs() {
  visited[0] = true;
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    for (auto i : adj[node]) {
      if (!visited[i]) {
        visited[i] = true;
        before[i] = node;
        q.push(i);
      }
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
    adj[a - 1].push_back(b - 1);
    adj[b - 1].push_back(a - 1);
  }

  bfs();

  if (!visited[n - 1]) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    vector<int> route;
    route.push_back(n - 1);
    int end = n - 1;
    while (end != 0) {
      route.push_back(before[end]);
      end = before[end];
    }
    reverse(route.begin(), route.end());
    cout << route.size() << endl;
    for (int i = 0; i < route.size(); i++) {
      cout << route[i] + 1 << ' ';
    }
    cout << endl;
  }

  return 0;
}
