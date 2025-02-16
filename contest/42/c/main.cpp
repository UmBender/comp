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
  vector<int> c(n);
  for (auto &i : c) {
    cin >> i;
  }
  vector<int> join;
  int acc = c.front();
  for (int i = 1; i < c.size(); i++) {
    if (acc < 0 && c[i] < 0) {
      acc += c[i];
      continue;
    }
    if (acc > 0 && c[i] > 0) {
      acc += c[i];
      continue;
    }
    join.push_back(acc);
    acc = c[i];
  }
  join.push_back(acc);

  vector<int> pref(join.size());
  vector<int> suf(join.size());

  if (join[0] > 0) {
    pref[0] = join[0];
  }

  for (int i = 1; i < join.size(); i++) {
    pref[i] = pref[i - 1];
    if (join[i] > 0) {
      pref[i] += join[i];
    }
  }

  if (join.back() < 0) {
    suf.back() = -join.back();
  }
  for (int i = join.size() - 2; i >= 0; i--) {
    suf[i] = suf[i + 1];
    if (join[i] < 0) {
      suf[i] -= join[i];
    }
  }

  int sum = 0;
  for (int i = 0; i < pref.size(); i++) {
    sum = max(sum, pref[i] + suf[i]);
  }

  cout << sum << endl;
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
