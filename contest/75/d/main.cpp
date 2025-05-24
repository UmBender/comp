// clang-format off
//#include <atcoder/all>
#include <bits/stdc++.h>
#include <cstdint>
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

int all_xor = 0LL;
int mmax    = 0LL;

int                 h, w;
vector<vector<int>> a;
vector<vector<int>> astate;

pair<int, int> next(int i, int j) {
    int next = i * w + j + 1;
    if (next >= h * w) {
        return {-1, -1};
    }
    return {next / w, next % w};
}

void dfs(int i, int j, int acc_x) {

    if (i == -1 && j == -1) {

        mmax = max(mmax, acc_x ^ all_xor);
        return;
    }

    if (j + 1 < w && astate[i][j] == 0 && astate[i][j + 1] == 0) {
        astate[i][j]     = 2;
        astate[i][j + 1] = 2;
        int nacc_x       = acc_x ^ a[i][j] ^ a[i][j + 1];
        auto [ni, nj]    = next(i, j);
        dfs(ni, nj, nacc_x);
        astate[i][j]     = 0;
        astate[i][j + 1] = 0;
    }

    if (i + 1 < h && astate[i][j] == 0 && astate[i+1][j] == 0) {

        astate[i][j]     = 1;
        astate[i + 1][j] = 1;
        int nacc_x       = acc_x ^ a[i][j] ^ a[i + 1][j];
        auto [ni, nj]    = next(i, j);
        dfs(ni, nj, nacc_x);
        astate[i][j]     = 0;
        astate[i + 1][j] = 0;
    }
    auto [ni, nj] = next(i, j);
    dfs(ni, nj, acc_x);
}

void solution() {
    cin >> h >> w;
    a      = vector<vector<int>>(h, vector<int>(w));
    astate = vector<vector<int>>(h, vector<int>(w));
    for (auto &i : a) {
        for (auto &j : i) {
            cin >> j;
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            all_xor ^= a[i][j];
        }
    }
    int accx = 0;

    dfs(0, 0, accx);
    cout << mmax << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // atcoder::modint::set_mod(998244353);
    solution();

    return 0;
}
