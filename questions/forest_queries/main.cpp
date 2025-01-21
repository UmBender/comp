#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl '\n'

#define MAX_INT ((int)1E18 + 1000)

void solution() {
  int n, q;
  cin >> n >> q;
  vector<vector<int>> map(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++) {
      map[i][j] = s[j] == '*' ? 1 : 0;
    }
  }

  vector<vector<int>> pref(n + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= n; i++) {
    int actual_sum = 0;
    for (int j = 1; j <= n; j++) {
      pref[i][j] = map[i - 1][j - 1] + actual_sum + pref[i - 1][j];
      actual_sum += map[i - 1][j - 1];
    }
  }

  /*for (int i = 0; i <= n; i++) {*/
  /*  for (int j = 0; j <= n; j++) {*/
  /*    cout << pref[i][j] << " \n"[j == n];*/
  /*  }*/
  /*}*/
  for (int i = 0; i < q; i++) {
    int y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;
    /*cout << "ALL: " << pref[y2][x2] << endl;*/
    cout << pref[y2][x2] - pref[y1 - 1][x2] - pref[y2][x1 - 1] +
                pref[y1 - 1][x1 - 1]
         << endl;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solution();

  return 0;
}
