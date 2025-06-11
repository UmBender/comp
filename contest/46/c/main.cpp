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
  string s;
  cin >> s;
  vector<char> result;
  for (int i = 0; i < s.size(); i++) {
    vector<char> acc;
    result.push_back(s[i]);

    while (result.size() >= 2 && result[result.size() - 1] == 'A' &&
           result[result.size() - 2] == 'W') {
      acc.push_back('C');
      result.pop_back();
      result.pop_back();
      result.push_back('A');
    }
    while(!acc.empty()) {
      result.push_back(acc.back());
      acc.pop_back();
    }
  }
  for(auto i: result) {
    cout << i;
  }
  cout << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  atcoder::modint::set_mod(998244353);
  solution();

  return 0;
}
