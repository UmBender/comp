#include <bits/stdc++.h>
#include <tuple>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll

void solution() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> ap(n, vector<int>(m));
  for (auto &p : ap) {
    for (auto &i : p) {
      cin >> i;
    }
  }
  // sum/index
  vector<tuple<int, int, vector<int>, int>> sums(n);
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j : ap[i]) {
      sum += j;
    }
    sums[i] = make_tuple(sum, 0, ap[i], i);
  }

  for (int i = 0; i < n; i++) {
    int sum = 0;
    int acc = 0;
    for (int j : ap[i]) {
      acc += j;
      sum += acc;
    }
    auto [first, second, third, fourth] = sums[i];
    sums[i] = make_tuple(first, sum, third, fourth);
  }

  sort(sums.rbegin(), sums.rend());
  vector<int> result(n * m);
  int actual = 0;

  for (auto &[a, b, c, i] : sums) {
    for (auto j : ap[i]) {
      result[actual] = j;
      actual++;
    }
  }
  int all_sum = 0;
  int acc = 0;
  for (int i : result) {
    acc += i;
    all_sum += acc;
  }
  cout << all_sum << endl;
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
