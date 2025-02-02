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
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }

  if (n == k) {
    vector<int> b;
    for (int i = 1; i < a.size(); i += 2) {
      b.push_back(a[i]);
    }
    b.push_back(0);
    for (int i = 0; i < b.size(); i++) {
      if (b[i] != i + 1) {
        cout << i + 1 << endl;
        return;
      }
    }
  }

  if (a[1] != 1) {
    cout << 1 << endl;
    return;
  }

  int joins = n - k;
  int pos = 2;
  while (joins) {
    if (a[pos] != 1) {
      cout << 1 << endl;
      return;
    }
    joins--;
    pos++;
  }
  cout << 2 << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    solution();
  }

  return 0;
}
