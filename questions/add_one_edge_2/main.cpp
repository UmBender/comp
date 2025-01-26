#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
vector<vector<uint64_t>> edges;
vector<uint64_t> edges_counter;
vector<bool> marked;

uint64_t bfs(uint64_t init_node) {
  uint64_t counter = 0;
  queue<uint64_t> nodes;
  nodes.push(init_node);
  marked[init_node] = true;
  while(!nodes.empty()) {
    uint64_t actual_node = nodes.front();
    for(auto i: edges[actual_node]) {
      if(edges_counter[i] ==3 && !marked[i]){
        marked[i] = true;
        nodes.push(i);
      }
      if(edges_counter[i] == 2) {
        counter++;
      }
    }
    nodes.pop();
  }

  return counter;
}

void solution() {
  int64_t n;
  cin >> n;
  edges = vector<vector<uint64_t>>(n);
  edges_counter = vector<uint64_t>(n);
  marked = vector<bool>(n, false);
  for (uint64_t i = 1; i < n; i++) {
    uint64_t x, y;
    cin >> x >> y;
    x--, y--;
    edges[x].push_back(y);
    edges[y].push_back(x);
  }

  for (uint64_t i = 0; i < n; i++) {
    edges_counter[i] = edges[i].size();
  }

  vector<uint64_t> sol;
  uint64_t counter = 0;
  for (int i = 0; i < n; i++) {
    if (edges_counter[i] == 3 && !marked[i]) {
      sol.push_back(bfs(i));
    }
  }
  for (auto &i : sol) {
    counter += (i * (i - 1)) / 2;
  }
  cout << counter << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  solution();

  return 0;
}
