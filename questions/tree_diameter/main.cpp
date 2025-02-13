#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll

pair<int,int> dfs(int actual_node, vector<vector<int>> &adj, int last ){
  pair<int,int> maxx = make_pair(0,actual_node);
  for(auto i: adj[actual_node]){
    if(i != last) {
      auto now = dfs(i, adj, actual_node);
      now.first++;
      if(now.first > maxx.first) {
        maxx = now;
      }
    }
  }
  return maxx;
}

void solution() {
  int n;
  cin >> n;
  vector<vector<int>>adj(n+1);
  for(int i = 0; i < n-1;i++){
    int a,b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  auto result =dfs(1,adj, 1);
  result = dfs(result.second, adj, result.second);
  cout << result.first << endl;
   
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  solution();

  return 0;
}
