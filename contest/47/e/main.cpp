#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
void __dbg() { cerr << endl; }
template <typename T> void __dbg(T t) { cerr << t << endl; }
template <typename T, typename... TRest> void __dbg(T first, TRest... rest) {
  cerr << first << ", ";
  __dbg(rest...);
}
#define dbg(...)                                                               \
  do {                                                                         \
    cerr << "DBG> " << "(" << #__VA_ARGS__ << ") = ";                          \
    __dbg(__VA_ARGS__);                                                        \
  } while (0)

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll
using mint = atcoder::modint;

int bs(function<int(int)> f, int target, int upper_bound) {
  int left = 0;
  int right = upper_bound;
  while (left <= right) {
    int middle = left + (right - left) / 2;
    if (f(middle) <= target && f(middle + 1) > target) {
      return middle;
    }

    if (f(middle) > target) {
      right = middle - 1;
    } else {
      left = middle + 1;
    }
  }
  return -1;
}

void solution() {
  int k;
  cin >> k;
  int actualk = k;
  vector<int> lines;

  while (actualk) {
    int paralel_now = bs(
        [](int i) {
          i--;
          return (i * i + i) / 2;
        },
        actualk, 500);
    lines.push_back(paralel_now);
    paralel_now--;
    actualk -= (paralel_now * paralel_now + paralel_now) / 2;
  }
  if (lines.empty()) {
    cout << 1 << endl;
    cout << 0 << ' ' << 0 << endl;
    return;
  }
  vector<pair<int, int>> first_line(lines[0]);
  int x = 0;
  int y = 0;
  for (auto &i : first_line) {
    i.first = x;
    i.second = y;
    x++;
  }
  vector<pair<int, int>> next;
  y++;
  for (int i = 1; i < lines.size(); i++) {
    for (int j = 0; j < lines[i] - 1; j++) {
      next.push_back({first_line[i - 1].first, y});
      y++;
    }
  }
  for (auto i : next) {
    first_line.push_back(i);
  }
  cout << first_line.size() << endl;
  for (auto i : first_line) {
    cout << i.first - ((int)1E9 - 100)<< " " << i.second - ((int)1E9 - 100)<< endl;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  atcoder::modint::set_mod(998244353);
  int t;
  cin >> t;
  while (t--)
    solution();

  return 0;
}
