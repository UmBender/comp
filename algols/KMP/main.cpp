// #include <atcoder/all>
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
// using mint = atcoder::modint;

vector<int> build_pi_s(string &s) {
  vector<int> pi_s(s.size());
  int len = 0;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] == s[len]) {
      len++;
      pi_s[i] = len;
    } else {
      while (len > 0) {
        len = pi_s[len - 1];
        if (s[i] == s[len]) {
          len++;
          pi_s[i] = len;
          break;
        }
      }
      if (len == 0) {
        pi_s[i] = 0;
      }
    }
  }
  return pi_s;
}

void kmp() {
  string n, m;
  cin >> n >> m;
  vector<int> pi_s = build_pi_s(m);
  vector<int> res;
  int i = 0, j = 0;
  while (i < n.size()) {
    if (m[j] == n[i]) {
      i++, j++;
      if (j == m.size()) {
        res.push_back(i - j);
        j = pi_s[j - 1];
      }
    } else {
      if (j != 0) {
        j = pi_s[j - 1];
      } else {
        i++;
      }
    }
  }
  cout << res.size() << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  // atcoder::modint::set_mod(998244353);
  solution();

  return 0;
}
