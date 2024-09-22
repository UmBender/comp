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

void solution() {
  int n, d, k;
  cin >> n >> d >> k;

  vector<pair<int, int>> days(k);
  for (int i = 0; i < k; i++) {
    cin >> days[i].first >> days[i].second;
    days[i].first--;
    days[i].second--;
  }
  vector<int> adds(n + 1);
  vector<int> removals(n + 1);

  vector<int> ranges(n + 1);
  for (int i = 0; i < k; i++) {
    ranges[days[i].second + 1]--;
    ranges[days[i].first]++;
    adds[days[i].first]++;
    removals[days[i].second + 1]++;
  }
  vector<int> count(n);
  vector<int> count_add(n);
  vector<int> count_rev(n);
  int acc = 0;
  count[0] = ranges[0];
  for (int i = 1; i < n; i++) {
    count[i] = count[i - 1] + ranges[i];
    count_add[i] = count_add[i - 1] + adds[i];
    count_rev[i] = count_rev[i - 1] + removals[i];
  }
  // cerr << "counts: ";
  // for (auto &i : count) {
  //   cerr << i << ' ';
  // }
  // cerr << endl;
  int start_brother = 0;
  int maxx = 0;
  int start_mother = 0;
  int minn = 0x3f3f3f;
  int last_sum = 0;
  for (int i = 0; i + k < n; i++) {
    if (count_add[i + k] - count_rev[i] > maxx) {
      maxx = count_add[i + k] - count_rev[i];
      start_brother = i;
    }
    if (count_add[i + k] - count_rev[i] < minn) {
      minn = count_add[i + k] - count_rev[i];
      start_mother = i;
    }
  }
  cout << start_brother + 1 << ' ' << start_mother + 1 << endl;
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
