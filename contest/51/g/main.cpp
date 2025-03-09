//#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

using ll = long long;
#define int ll

int fact(int n) {
  int base = 1;
  for(int i = 2; i <= n;i++) {
    base *=i;
  }
  return base;
}

void solution() {
  int n;
  cin >> n;
  int val = fact(n);
  cout << val % 10 << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while(t--)
    solution();

  return 0;
}
