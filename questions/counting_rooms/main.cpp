#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

int visited[1010][1010];
char grid[1010][1010];
int n, m;

void dfs(int i, int j) {
  if (i < 0 || j < 0 || i >= n || j >= m) {
    return;
  }
  if (grid[i][j] == '#' || visited[i][j] == true) {
    return;
  }

  visited[i][j] = true;
  dfs(i + 1, j);
  dfs(i - 1, j);
  dfs(i, j + 1);
  dfs(i, j - 1);
}

int solution() {
  int counter = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (visited[i][j] || grid[i][j] == '#') {
        continue;
      }
      dfs(i, j);
      counter++;
    }
  }
  return counter;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  cin >> n >> m;
  string elements;
  for (int i = 0; i < n; i++) {
    cin >> grid[i];
    for (int j = 0; j < m; j++) {
      visited[i][j] = false;
    }
  }

  cout << solution() << endl;
  return 0;
}
