#include <bits/stdc++.h>

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

int gcd(int a, int b) {
  int i, r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}

void solution() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }

  vector<pair<int, int>> an(n);
  vector<pair<int, int>> ak(n);
  for (int i = 0; i < n; i++) {
    an[i] = make_pair(a[i], i);
    ak[i] = make_pair(a[i], i);
  }
  sort(an.begin(), an.end());
  sort(ak.begin(), ak.end());
  int counter = 0;
  for (int i = 1; i < n; i++) {
    if (ak[i].first >= ak[i - 1].first) {
      if (ak[i].first % ak[i - 1].first) {
        ak[i].first += (ak[i - 1].first - (ak[i].first % ak[i - 1].first));
        counter++;
      }
    } else {
      ak[i].first += ak[i - 1].first - ak[i].first;
      counter++;
    }
  }

  cout << counter << endl;

  for (int i = 1; i < n; i++) {
    if (ak[i].first == an[i].first) {
      continue;
    }
    cout << ak[i].second + 1 << ' ' << ak[i].first - an[i].first << endl;
  }
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
