#include <algorithm>
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

vector<vector<int>> adj;
vector<int> dp;
vector<bool> used;
vector<bool> real_used;

int maxx(int node, bool minus) {
  used[node] = true;
  vector<pair<int, int>> solves;
  for (int i : adj[node]) {
    if (!used[i])
      solves.push_back({maxx(i, true), i});
  }
  if (solves.size() < 4 - minus) {
    used[node] = false;
    return 0;
  }
  sort(solves.rbegin(), solves.rend());
  int acc = 0;
  for (int i = 0; i < 4 - minus; i++) {
    acc += solves[i].first + 1;
    real_used[solves[i].second] = true;
  }
  used[node] = false;
  return acc;
}

void solution() {
  int n;
  cin >> n;
  adj = vector<vector<int>>(n);
  dp = vector<int>(n);
  used = vector<bool>(n);
  real_used = vector<bool>(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a - 1].push_back(b - 1);
    adj[b - 1].push_back(a - 1);
  }
  int max_value = -1;
  for (int i = 0; i < n; i++) {
    if (real_used[i] || adj[i].size() < 4)
      continue;
    max_value = max(maxx(i, false) + 1, max_value);
    real_used[i] = true;
  }
  cout << max_value << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  atcoder::modint::set_mod(998244353);
  solution();

  return 0;
}
