#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll

void solution() {
  int n;
  cin >>n;
  vector<int>a(n);
  vector<int>b(n);
  for(auto &i: a) {
    cin >> i;
  }
  for(auto &i: b) {
    cin >> i;
  }
  int acc = 0;
  for(int i = 0; i < n- 1; i++) {
    if(a[i] > b[i+1]) {
      acc += a[i] - b[i+1];

    }
  }
  cout << acc + a.back() << endl;
  

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
