#include <bits/stdc++.h>
#include <climits>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  vector<int> x(n);
  for (auto &i : x) {
    cin >> i;
  }

  int sum = 0, maximum = INT_MIN;

  for (int i = 0; i < n; i++) {
    sum += x[i];
    maximum = max(maximum, sum);

    if (sum < 0) {
      sum = 0;
    }
  }
  cout << maximum << endl;

  return 0;
}
