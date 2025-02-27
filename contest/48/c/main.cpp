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

pair<int, int> get_lim(set<int> &s, int x) {
  auto upper = s.upper_bound(x);
  int upper_val = (upper != s.end()) ? *upper : -1;
  auto lower = s.lower_bound(x);
  int lower_val = 0;
  if (lower != s.begin()) {
    --lower;
    lower_val = *lower;
  } else {
    lower_val = -1;
  }
  return {lower_val, upper_val};
}

void solution() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }

  vector<tuple<int, int, char>> caps(n);
  for (int i = 0; i < n; i++) {
    caps[i] = {a[i], i, s[i]};
  }
  sort(caps.rbegin(), caps.rend());

  set<int> inserted_reds;
  set<int> inserted_blues;
  for (int i = 0; i < caps.size(); i++) {
    auto [red_left, red_right] = get_lim(inserted_reds, get<1>(caps[i]));
    auto [blue_left, blue_right] = get_lim(inserted_blues, get<1>(caps[i]));

    if (get<2>(caps[i]) == 'R') {
      if (blue_left == -1 || blue_right == -1) {
        inserted_reds.insert(get<1>(caps[i]));
        continue;
      }
      if (red_left != -1 && blue_left < red_left) {
        inserted_reds.insert(get<1>(caps[i]));
        continue;
      }
      if (red_right != -1 && blue_right > red_right) {
        inserted_reds.insert(get<1>(caps[i]));
        continue;
      }
      if (k) {
        k--;
        inserted_reds.insert(get<1>(caps[i]));
        continue;
      }
      cout << get<0>(caps[i]) << endl;
      return;
    } else {
      if (red_right != -1 && blue_right != -1 && red_right > blue_right) {
        inserted_blues.insert(get<1>(caps[i]));
        continue;
      }
      if (red_right == -1 && blue_right != -1) {
        inserted_blues.insert(get<1>(caps[i]));
        continue;
      }
      if (red_left != -1 && blue_left != -1 && blue_left > red_left) {
        inserted_blues.insert(get<1>(caps[i]));
        continue;
      }
      if (red_left == -1 && blue_left != -1) {
        inserted_blues.insert(get<1>(caps[i]));
        continue;
      }
      if (k) {
        k--;
        inserted_blues.insert(get<1>(caps[i]));
        continue;
      } else {
        cout << get<0>(caps[i]) << endl;
        return;
      }
    }
  }
  cout << 0 << endl;
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
