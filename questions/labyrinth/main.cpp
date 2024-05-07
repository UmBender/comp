#include <bits/stdc++.h>
#include <utility>
using namespace std;

#define ii pair<int, int>

char grid[1010][1010];
bool visited[1010][1010];
int previous[1010][1010];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, m;

void solution() {
  ii begin, end;

  queue<ii> q;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 'A') {
        begin = make_pair(i, j);
      }
      if (grid[i][j] == 'B') {
        end = make_pair(i, j);
      }
    }
  }
  q.push(begin);
  visited[begin.first][begin.second] = true;

  while (!q.empty()) {
    ii u = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      ii v = make_pair(u.first + dx[i], u.second + dy[i]);
      if (v.first < 0 || v.first >= n || v.second < 0 || v.second >= m) {
        continue;
      }
      if (grid[v.first][v.second] == '#') {
        continue;
      }
      if (visited[v.first][v.second]) {
        continue;
      }
      visited[v.first][v.second] = true;
      previous[v.first][v.second] = i;
      q.push(v);
    }
  }

  if (visited[end.first][end.second]) {
    cout << "YES" << endl;
    vector<int> steps;
    while (end != begin) {
      int p = previous[end.first][end.second];
      steps.push_back(p);
      end = make_pair(end.first - dx[p], end.second - dy[p]);
    }

    cout << steps.size() << endl;

    for (int i = steps.size() - 1; i >= 0; i--) {
      switch (steps[i]) {
      case 0:
        cout << 'U';
        break;
      case 1:
        cout << 'R';
        break;
      case 2:
        cout << 'D';
        break;
      case 3:
        cout << 'L';
        break;
      }
    }
  }else{
		cout << "NO" << endl;
	}
}

int32_t main() {

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> grid[i];
    for (int j = 0; j < m; j++) {
      visited[i][j] = false;
    }
  }

  solution();

  return 0;
}
