#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

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
  long long n;
  cin >> n;
  vector<long long> bit_set(256, -1);
  long long pos = 0;
  long long ones = 0;
  for (long long i = 1LL; (i >> 62LL) < 1LL; i *= 2LL) {
    if ((n & i)) {
      bit_set[pos] = 1;
      ones++;
    } else {
      bit_set[pos] = 0;
    }
    pos++;
  }
  vector<long long> numbers;

  numbers.push_back(n);

  for (long long i = 0; i < bit_set.size(); i++) {
    if (bit_set[i] == 1) {
      long long val = n - (1LL << i);
      if (val != 0)
        numbers.push_back(val);
    }
  }
  reverse(numbers.begin(), numbers.end());
  cout << numbers.size() << endl;
  for (auto i : numbers) {
    cout << i << ' ';
  }
  cout << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solution();
  }

  return 0;
}
