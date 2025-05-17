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
    int h, w, n;
    cin >> h >> w >> n;
    map<int, map<int, int>> grid;
    map<int, map<int, int>> rev_grid;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        grid[y][x]     = 1;
        rev_grid[x][y] = 1;
    }
    int q;
    cin >> q;
    while (q--) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            int x;
            cin >> x;
            for (auto [y, _] : rev_grid[x]) {
                grid[y].erase(x);
            }
            cout << rev_grid[x].size() << endl;
            rev_grid.erase(x);
        }
        if (opt == 2) {
            int y;
            cin >> y;
            for (auto [x, _] : grid[y]) {
                rev_grid[x].erase(y);
            }
			cout << grid[y].size() << endl;
			grid.erase(y);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // atcoder::modint::set_mod(998244353);
    solution();

    return 0;
}
