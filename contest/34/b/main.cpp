#include <bits/stdc++.h>
#include <numeric>

using namespace std;

using ll = long long;
#define int ll
#define endl '\n'

#define MAX_INT ((int)1E18 + 1000)

void solution() {

  int n;
  cin >> n;
  vector<string> adj(n);
  for (int i = 0; i < n; i++) {
    cin >> adj[i];
  }
  vector<int> p(n);
  iota(p.begin(), p.end(), 1);
  sort(p.begin(), p.end(), [&](int i, int j) {
    if (adj[i-1][j-1] == '1') {
      return i < j;
    }
    return i > j;
  });
  for (int i = 0; i < n; i++) {
    cout << p[i] << " \n"[i == n - 1];
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solution();
  }

  return 0;
}
