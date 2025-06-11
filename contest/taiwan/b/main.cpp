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
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }

  vector<int> fixed(n);
  for (int i = 0; i < n; i++) {
    fixed[i] = a[i] > 0 ? a[i] : -a[i];
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += fixed[i];
  }

  int max_sum = sum;  
  int actual_sum = sum;
  for(int i = 0; i < n;i ++) {
    if(a[i] < 0) {
      actual_sum += 3 * a[i];
    }else{
      actual_sum += a[i];
    }

    if(actual_sum > max_sum) {
      max_sum = actual_sum;
    }
    if(actual_sum < sum) {
      actual_sum = sum;
    }
  }
  cout << max_sum << endl;


  

}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  solution();

  return 0;
}
