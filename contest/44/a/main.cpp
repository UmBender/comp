// #include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll

void solution() {
  int n;
  cin >> n;
  n-=2;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  for(int i = 0; i < n - 2;i ++) {
    if(a[i] == 1 && a[i+1] == 0 && a[i+2] == 1) {
      cout << "NO" << endl;
      return;
    }
  }


  cout << "YES" << endl;
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
