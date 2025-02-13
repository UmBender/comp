#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }

using ll = long long;
#define int ll

void solution() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n + 1);
  vector<bool> used(n + 1);
  vector<int> actual_size(n+1);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  queue<int> elements;
  for (int i = 1; i <= n; i++) {
    if (adj[i].size() == 1) {
      elements.push(i);
    }
    actual_size[i] = adj[i].size();
  }
  int counter = 0;
  while (!elements.empty()) {
    int actual = elements.front();
    elements.pop();
    if (!used[actual]) {
      int not_used = -1;
      for (auto i : adj[actual]) {
        if (!used[i]) {
          not_used = i;
        }
      }
      if (not_used != -1) {
        counter++;
        used[not_used] = true;
        used[actual] = true;
        for (auto i : adj[not_used]) {
          actual_size[i] --;
          if (!used[i] && i != actual && actual_size[i] == 1) {
            elements.push(i);
          }
        }
      }
    }
  }
  cout << counter << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  solution();

  return 0;
}
