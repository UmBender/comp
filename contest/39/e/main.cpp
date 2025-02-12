#include <bits/stdc++.h>
#include <numeric>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }

using ll = long long;
#define int ll

struct DSU {
  vector<int> parents;
  vector<int> sizes;
  int size;
  DSU(int size) : parents(size + 1), sizes(size + 1, 1), size(size) {
    iota(parents.begin(), parents.end(), 0);
  }
  int get_parent(int node) {
    if (parents[node] == node) {
      return node;
    }
    parents[node] = get_parent(parents[node]);
    return parents[node];
  }

  bool is_join(int first, int second) {
    first = get_parent(first);
    second = get_parent(second);
    return first == second;
  }

  void join(int first, int second) {
    first = get_parent(first);
    second = get_parent(second);
    if (first == second) {
      return;
    }

    if (sizes[first] < sizes[second]) {
      swap(first, second);
    }

    sizes[first] += sizes[second];
    parents[second] = first;
  }

  int get_size(int node) { return sizes[get_parent(node)]; }
};
int bs(int target, vector<int> &arr) {
  int left = 0;
  int right = arr.size() - 1;
  while (left <= right) {
    int middle = left + (right - left) / 2;
    if (arr[middle] == target) {
      return middle;
    }

    if (arr[middle] > target) {
      right = middle - 1;
    } else {
      left = middle + 1;
    }
  }
  return -1;
}

int dfs(vector<bool> &visited, vector<vector<int>> &g1, vector<vector<int>> &g2,
        DSU &graph1, DSU &graph2, int node) {
  int counter = 0;
  visited[node] = true;
  for (auto i : g1[node]) {
    if (!visited[i]) {
      visited[i] = true;
      counter += dfs(visited, g1, g2, graph1, graph2, i);
    }
    if (!graph1.is_join(node, i)) {
      counter++;
    } else {
      graph2.join(node, i);
    }
  }
  return counter;
}

void solution() {
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  vector<vector<int>> g1(n + 1), g2(n + 2);
  DSU graph1(n), graph2(n);

  for (int i = 0; i < m1; i++) {
    int n1, n2;
    cin >> n1 >> n2;
    g1[n1].push_back(n2);
    g1[n2].push_back(n1);
  }

  for (int i = 0; i < m2; i++) {
    int n1, n2;
    cin >> n1 >> n2;
    g2[n1].push_back(n2);
    g2[n2].push_back(n1);
    graph2.join(n1, n2);
  }

  vector<bool> visited(n + 1);
  int counter = 0;
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      counter += dfs(visited, g1, g2, graph2, graph1, i);
    }
  }
  counter /= 2;

  fill(visited.begin(), visited.end(), false);
  for (int i = 1; i <= n; i++) {
    for (auto j : g2[i]) {
      if (!graph1.is_join(i, j)) {
        if (bs(j, g1[i]) == -1) {
          counter++;
        }
        graph1.join(i, j);
      }
    }
  }
  cout << counter << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solution();

  return 0;
}
