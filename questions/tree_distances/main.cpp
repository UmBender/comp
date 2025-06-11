#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll

pair<int, int> dfs(int actual_node, vector<vector<int>> &adj,
                           int last_node) {
  auto base = make_pair(actual_node, 0);
  cout << base.first << endl;
  for (int i : adj[actual_node]) {
    if (i != last_node) {
      auto path = dfs(i, adj, actual_node); path.second++;
      if (path.second> base.second) {
        base = path;
      }
    }
  }
  cout << base.first << endl;
  return base;
}

void other_dfs(int actual_node, vector<vector<int>>& adj, vector<int> &path, vector<int> &maxx_dist, int last_node) {
  if(actual_node == path.back()){
    path.pop_back();
    maxx_dist[actual_node] = max(maxx_dist[actual_node], (int)path.size());
    for(auto i: adj[actual_node]) {
      if(i!= last_node) {
        other_dfs(i, adj,path,maxx_dist, actual_node);
      }
    }
    path.push_back(actual_node);

  }else{
    path.push_back(actual_node);
    maxx_dist[actual_node] = max(maxx_dist[actual_node],(int)path.size());
    for(auto i: adj[actual_node]) {
      if(i != last_node) {
        other_dfs(i, adj,path, maxx_dist, actual_node);
      }
    }
    path.pop_back();
  }
}


void solution() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  auto base = dfs(1, adj, 1);

  /*base.second.push_back(1);*/
  /**/
  /*vector<int> dists(n+1,0);*/
  /*auto other = dfs(base.first, adj, base.first);*/
  /*other.second.push_back(base.first);*/
  /*cout << endl;*/
  /*vector<int> cloned = other.second;*/
  /*reverse(cloned.begin(), cloned.end());*/
  /*other_dfs(other.first, adj,cloned, dists, other.first);*/
  /**/
  /*other_dfs(other.second.back(), adj, other.second, dists, other.second.back());*/
  /**/
  /*for(int i = 1; i <= n; i++) {*/
  /*  cout << dists[i] << " \n"[i==n];*/
  /*}*/
  /**/
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  solution();

  return 0;
}
