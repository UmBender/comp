#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define int ll

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }

struct BIT {
  vector<vector<int>> bit;
  BIT(vector<vector<int>> a) : bit(a.size() + 1, vector<int>(a[0].size() + 1)) {
    for (int i = 0; i < a.size(); i++) {
      for (int j = 0; j < a[0].size(); j++) {
        update(i, j, a[i][j]);
      }
    }
  }

  void update(int y, int x, int value) {
    int idy, idx;
    idy = y + 1;
    while (idy < bit.size()) {
      idx = x + 1;
      while (idx < bit[0].size()) {
        bit[idy][idx] += value;
        idx += (idx & -idx);
      }
      idy += (idy & -idy);
    }
  }

  int sum(int y, int x) {
    int counter = 0;
    int idy = y + 1;
    while (idy > 0) {
      int idx = x + 1;
      while (idx > 0) {
        counter += bit[idy][idx];
        idx -= (idx & -idx);
      }
      idy -= (idy & -idy);
    }
    return counter;
  }

  int query(int by, int ey, int bx, int ex) {
    int counter = 0;
    counter += sum(ey, ex);
    counter -= sum(ey, bx - 1);
    counter -= sum(by - 1, ex);
    counter += sum(by - 1, bx - 1);
    return counter;
  }
};

void solution() {
  int n, q;
  cin >> n >> q;
  vector<vector<int>> grid(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    vector<int> a(n);
    for (int j = 0; j < n; j++) {
      a[j] = s[j] == '*' ? 1 : 0;
    }
    grid[i] = a;
  }

  auto ft = BIT(grid);
  for (int i = 0; i < q; i++) {
    int op;
    cin >> op;
    if (op == 1) {
      int y, x;
      cin >> y >> x;
      y--, x--;
      ft.update(y, x, 2 * (1 - grid[y][x]) - 1);
      grid[y][x] = 1 - grid[y][x];
    } else {
      int y1, y2, x1, x2;
      cin >> y1 >> x1 >> y2 >> x2;
      y1--, y2--, x1--, x2--;
      cout << ft.query(y1, y2, x1, x2) << endl;
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  solution();

  return 0;
}
