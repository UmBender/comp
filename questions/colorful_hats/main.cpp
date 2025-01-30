#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }

void solution() {
  int64_t n;
  cin >> n;
  int64_t minn = MAX_INT, maxx = 0;

  vector<int64_t> a(n);

  for (auto &i : a) {
    cin >> i;
    minn = min(i, minn);
    maxx = max(i, maxx);
  }

  if (maxx - minn > 1) {
    cout << "No" << endl;
    return;
  }

  if (maxx == minn) {
    if (n - 1 == maxx) {
      cout << "Yes" << endl;
      return;
    }
    if (maxx * 2 <= n) {
      cout << "Yes" << endl;
      return;
    }
    cout << "No" << endl;
    return;
  }

  int64_t maxcount = 0;
  for (auto i : a) {
    if (i == maxx)
      maxcount++;
  }

  int64_t mincount = a.size() - maxcount;
  if (mincount < maxx && 2 * (maxx - mincount) <= maxcount) {
    cout << "Yes" << endl;
    return;
  }
  cout << "No" << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  solution();

  return 0;
}
