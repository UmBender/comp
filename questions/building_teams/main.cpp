#include <bits/stdc++.h>
#include <queue>
#include <vector>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10
#define f front

int n, m;

vector<vector<int>> adj(100010);
vector<bool> acessed(100010, false);
vector<int> color(100010, -1);
vector<int> origin(100010, -1);

bool solution() {
  for (int i = 0; i < n; i++) {
    if (!acessed[i]) {
      queue<int> q;
      color[i] = 0;
      acessed[i] = true;
      q.push(i);
      while (!q.empty()) {
        int element = q.f();
        q.pop();
        for (auto j : adj[element]) {
          if (acessed[j]) {
            if (color[j] == color[element]) {
              return false;
            } else {
              continue;
            }
          } else {
						acessed[j] = true;
            color[j] = 1 - color[element];
            q.push(j);
          }
        }
      }
    }
  }
  return true;
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

  bool a = solution();
  if (a == true) {
    for (int i = 0; i < n; i++) {
      if (color[i] == 0) {
        cout << "1 ";
      } else {
        cout << "2 ";
      }
    }
    cout << endl;

  } else {
    cout << "IMPOSSIBLE";
  }

  return 0;
}
