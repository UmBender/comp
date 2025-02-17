// #include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll

void solution() {
  int n, k;
  cin >> n >> k;
  vector<pair<int,int>> a(n);
  for (auto &i : a) {
    cin >> i.first;
  }
  for(int i = 0; i < n; i++) {
    a[i].second = i;
  }
  sort(a.begin(), a.end());

  for (int i = 0; i < n; i++) {
    int counter = 0;
    for (int j = 0; j < n; j++) {
      if (i == j) {
        continue;
      }
      if (abs(a[i].first - a[j].first) % k == 0) {
        counter++;
      }
    }
    if(counter == 0) {
      cout << "YES" << endl;
      cout << a[i].second + 1 << endl;
      return;
    }
  }
  cout << "NO" << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solution();

  return 0;
}
