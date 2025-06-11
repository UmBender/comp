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
  vector<char> stack;
  for (auto i : s) {
    switch (i) {
    case '(':
    case '[':
    case '<':
      stack.push_back(i);
      break;
    case ')':
      if (stack.empty() || stack.back() != '(') {
        cout << "No" << endl;
        return;
      } else {
        stack.pop_back();
      }
      break;
    case ']':
      if (stack.empty() || stack.back() != '[') {
        cout << "No" << endl;
        return;
      } else {
        stack.pop_back();
      }
      break;
    case '>':
      if (stack.empty() || stack.back() != '<') {
        cout << "No" << endl;
        return;
      } else {
        stack.pop_back();
      }
      break;
    }
  }
  if (stack.empty()) {
    cout << "Yes" << endl;
    return;
  }
  cout << "No" << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  atcoder::modint::set_mod(998244353);
  solution();

  return 0;
}
