#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

int m, n, k;
vector<int> a, b;

int solution() {
  int counter = 0;
  int new_m = a.size()-1;
	int new_n = b.size()-1;
  while (new_m >= 0 && new_n >= 0) {
    if (b[new_n] - k <= a[new_m] && a[new_m] <= b[new_n] + k) {
      counter++;
      new_m--;
      new_n--;
      continue;
    }
    if (a[new_m] > b[new_n] + k) {
      new_m--;
      continue;
    }
    if (b[new_n] - k > a[new_m]) {
      new_n--;
      continue;
    }
  }
  return counter;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    int d = 0;
    cin >> d;
    a.push_back(d);
  }
  for (int i = 0; i < m; i++) {
    int d = 0;
    cin >> d;
    b.push_back(d);
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int counter = solution();
  cout << counter << endl;

  return 0;
}
