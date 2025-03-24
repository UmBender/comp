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
    int n, m;
    cin >> n >> m;
    vector<string> ggrid(n);
    for (auto &i : ggrid) {
        cin >> i;
    }
    vector<vector<bool>> grid(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ggrid[i][j] == '1') {
                grid[i][j] = true;
            }
        }
    }
    vector<vector<bool>> down(n, vector<bool>(m));
    vector<vector<bool>> left(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        left[i][0] = true;
    }
    for (int i = 0; i < m; i++) {
        down[0][i] = true;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] && (!down[i][j] && !left[i][j])) {
                cout << "NO" << endl;
                return;
            }
            if (j != m - 1 && left[i][j] && grid[i][j]) {
                left[i][j + 1] = true;
            }
            if (i != n - 1 && down[i][j] && grid[i][j]) {
                down[i + 1][j] = true;
            }
        }
    }
    cout << "YES" << endl;
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
