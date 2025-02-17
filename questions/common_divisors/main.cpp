//#include <atcoder/all>
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
  vector<int> a(1000050);
  int max_num = 0;
  for(int i = 0; i < n; i++) {
    int val;
    cin >> val;
    a[val]++;
    if(a[val] >= 2) {
      max_num = max(max_num, val);
    }
  }

  int max_div = 1;
  for(int i = 2; i < 1000050; i++) {
    int counter = 0;
    for(int j = i; j < 1000050; j+= i) {
      counter += a[j];
    }
    if(counter >= 2) {
      max_div = max(max_div, i);
    }
  }
  cout << max(max_div, max_num) << endl;
  
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  solution();

  return 0;
}
