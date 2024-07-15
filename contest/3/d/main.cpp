#include <bits/stdc++.h>
#include <vector>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

int sum_pcol(vector<vector<int>> &a, int i, int j) {
  int sum = 0;
  while (i < a.size() && j < a[0].size()) {
    sum += a[i][j];
    i++;
    j++;
  }
  return sum;
}

int sum_rcol(vector<vector<int>> &a, int i, int j) {
  int sum = 0;
  while (i < a.size() && j >= 0) {
    sum += a[i][j];
    i++;
    j--;
  }
  return sum;
}

void solution() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n);
  for (int i = 0; i < n; i++) {
    vector<int> hold(m);
    for (int j = 0; j < m; j++) {
      cin >> hold[j];
    }
    a[n] = hold;
  }
	vector<int> prim(n+m-1);
	vector<int> rev
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solution();
  }

  return 0;
}
