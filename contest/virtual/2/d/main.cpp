// clang-format off
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
//using mint = atcoder::modint;
// clang-format on

void solution() {
    int n, m;
    cin >> n >> m;
    vector<int>         acc;
    vector<vector<int>> sols;
    auto                dfs = [&](auto dfs, vector<int> v) -> void {
        int sz = v.size();
        if (sz == n) {
            sols.push_back(v);
            return;
        }
        for (int i = (sz == 0 ? 1 : v.back() + 10); i < m - 10 * (n - sz -1)+1;
             i++) {
			vector<int> next = v;
			next.push_back(i);
            dfs(dfs, next);
        }
    };
    dfs(dfs, acc);
	cout << sols.size() << endl;
    for (auto &i : sols) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // atcoder::modint::set_mod(998244353);
    solution();

    return 0;
}
