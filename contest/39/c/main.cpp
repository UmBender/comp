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
  vector<int> x(n);
  for (auto &i : x) {
    cin >> i;
  }
  sort(x.begin(), x.end());
  int i = 0, j = n - 1;
  int counter = 0;
  while (i < j) {
    int sum = x[i] + x[j];
    if (sum == k) {
      counter++, i++, j--;
    } else if (sum > k) {
      j--;
    } else {
      i++;
    }
  }
  cout << counter << endl;
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
