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

void solution() {
  string s, t;
  cin >> s >> t;
  vector<int> counter(256, -1);
  for (int i = 0; i < t.size() - 1; i++) {
    counter[t[i]] = i;
  }
  string ans;
  int ans_size = MAX_INT;
  for (int i = 1; i < s.size(); i++) {
    if (counter[s[i]] == -1) {
      continue;
    }
    if (i + t.size() - counter[s[i]] >= ans_size) {
      continue;
    }
    string new_ans;
    for (int j = 0; j < i; j++) {
      new_ans.push_back(s[j]);
    }
    for (int j = counter[s[i]]; j < t.size(); j++) {
      new_ans.push_back(t[j]);
    }
    ans = new_ans;
    ans_size = new_ans.size();
  }
  if (ans_size == MAX_INT)
    cout << -1 << endl;
  else
    cout << ans << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  solution();

  return 0;
}
