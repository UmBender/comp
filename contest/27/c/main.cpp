#include <bits/stdc++.h>
#include <deque>
#include <numeric>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

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

void solution() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int money = ((n) * (n + 1)) / 2;
  vector<int> prices(n);
  vector<int> zeros(n);
  vector<int> ones(n);
  int counter = n;
  iota(prices.begin(), prices.end(), 1);

  if (s.front() == '1') {
    zeros[0] = 0;
    ones[0] = 1;
  } else {
    zeros[0] = 1;
    ones[0] = 0;
  }
  for (int i = 1; i < n; i++) {
    if (s[i] == '1') {
      zeros[i] = zeros[i - 1];
      ones[i] = ones[i - 1] + 1;
    } else {
      zeros[i] = zeros[i - 1] + 1;
      ones[i] = ones[i - 1];
    }
  }

  reverse(s.begin(), s.end());
  reverse(prices.begin(), prices.end());
  int i = 0;

  int count1 = 0;
  int one = 0;
  int zero = 0;
  deque<int> possible;
  while (i < n) {
    if (s[i] == '1') {
      possible.push_back(prices[i]);
      i++;
    } else {
      if (possible.empty()) {
        i++;
      } else {
        int val = possible.front();
        possible.pop_front();
        money -= val;
        i++;
      }
    }
  }
  while (possible.size() > 1) {
    int val = possible.front();
    possible.pop_front();
    possible.pop_back();
    money -= val;
  }

  cout << money << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solution();
  }

  return 0;
}
