// clang-format off
//#include <atcoder/all>
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
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n));
    vector<bool>        used(2 * n + 1, false);
    vector<int>         p(2 * n);
    for (auto &i : g) {
        for (auto &j : i) {
            cin >> j;
        }
    }
    for (int i = 0; i < n; i++) {
        p[i + 1]      = g[0][i];
        used[g[0][i]] = true;
    }
    for (int i = 1; i < n; i++) {
        p[n + i]          = g[i][n - 1];
        used[g[i][n - 1]] = true;
    }
    for (int i = 1; i < used.size(); i++) {
        if (!used[i]) {
            p[0] = i;
            break;
        }
    }
    for (int i = 0; i < p.size(); i++) {
        cout << p[i] << " \n"[i == p.size() - 1];
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // atcoder::modint::set_mod(998244353);
    int t;
    cin >> t;
    while (t--)
        solution();

    return 0;
}
