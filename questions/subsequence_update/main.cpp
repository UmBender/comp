#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }

using ll = long long;

#define int ll

void solution() {
  int n, l, r;
  cin >> n >> l >> r;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  vector<int> a1, a2;
  for(int i = 0; i < r;i++) {
    a1.push_back(a[i]);
  }
  for(int i = l-1; i < n; i++) {
    a2.push_back(a[i]);
  }

  sort(a1.begin(), a1.end());
  sort(a2.begin(), a2.end());
  int counter1 = 0, counter2= 0;
  for (int i = 0; i <= r - l; i++) {
    counter1 += a1[i];
  }
  for (int i = 0; i <= r - l; i++) {
    counter2 += a2[i];
  }

  cout << min(counter1,counter2) << endl;
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
