#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll

int max(int i, int j) { return i > j ? i : j; }

void solution() {
  int n, m;
  cin >> n >> m;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    sum += val;
  }

  cout << max(sum - m,0) << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t > 0) {
    solution();

    t--;
  }

  return 0;
}
