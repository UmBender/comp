#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl '\n'

#define MAX_INT ((int)1E18 + 1000)

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

int pl10(int val) {
  int i = 1;
  while (!(i <= val && i * 10 > val)) {
    i *= 10;
  }
  return i;
}
map<int, int> roundup;
int get_roundup(int p10) {
  if (p10 == 1) {
    roundup[1] = 0;
    return 0;
  }
  if (p10 == 10) {
    return 5;
  }
  if (roundup.count(p10) == 0) {
    int counter = 0;
    for (int i = 5; i <= 9; i++) {
      counter += p10 / 10;
    }
    counter += get_roundup(p10 / 10);
    roundup[p10] = counter;
    return counter;
  }
  return roundup[p10];
}

int decimal_roundup(int val) {
  int first_digit = val / pl10(val);
  if (val < 10) {
    return val - 4;
  }
  if (first_digit == 4) {
    return decimal_roundup(val - first_digit * pl10(val));
  }
  if (first_digit >= 5) {
    int counter = 0;
    counter += get_roundup(pl10(val));
    counter += val - pl10(val) * 5;
    counter++;
    return counter;
  }
  return 0;
}

void solution() {
  int n;
  cin >> n;
  int counter = 0;
  int sup = 10;

  while (5 * sup <= n) {
    counter += get_roundup(sup);
    sup *= 10;
  }

  if (sup * 4 < n) {
    int deps = n % (4 * sup);
    counter += decimal_roundup(deps);
  }
  cout << counter << endl;
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
