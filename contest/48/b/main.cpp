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

void solution() {
  int n, x, k;
  cin >> n >> x >> k;
  string s;
  cin >> s;
  int i = 0;
  int position = x;
  int moment = 0;
  int counter = 0;

  counter += position == 0;

  do {
    if (s[i] == 'L') {
      position--;
    } else {
      position++;
    }
    moment++;
    i++;
  } while (moment < k && position != 0 && i < n);
  counter += position == 0;
  if (moment == k) {
    cout << counter << endl;
    return;
  }
  if (i == n && position != 0) {
    cout << counter << endl;
    return;
  }

  i = 0;

  string cycle_move = "";
  do {
    cycle_move.push_back(s[i]);
    if (s[i] == 'L') {
      position--;
    } else {
      position++;
    }
    i++;
    moment++;
  } while (moment < k && position != 0 && i < n);

  counter += position == 0;

  if (moment == k) {
    cout << counter << endl;
    return;
  }

  if (position != 0 && i == n) {
    cout << counter << endl;
    return;
  }

  int rest_time = k - moment;
  counter += rest_time / cycle_move.size();
  cout << counter << endl;
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
