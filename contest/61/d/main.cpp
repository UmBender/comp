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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> joins(m + 1);
    int                 actual_size   = 0;
    int                 actual_number = 0;
    int                 space         = n;
    int                 line          = 0;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j < k && space; j++) {
            joins[i].push_back(0);
            space--;
        }
    }
    while (space) {
        joins[line].push_back(0);
        space--;
        line++;
        line %= m + 1;
    }
    if (joins.back().empty()) {
        for (int i = 0; i < n; i++) {
            cout << 0 << " \n"[i == n - 1];
        }
        return;
    }
    for (int i = 0; i < joins.front().size(); i++) {
        for (int j = 0; j < joins.size(); j++) {
            if (i >= joins[j].size()) {
                break;
            }
            joins[j][i] = i;
        }
    }
    vector<int> joined;
    for (int i = 0; i < joins.size(); i++) {
        for (int j = 0; j < joins[i].size(); j++) {
            joined.push_back(joins[i][j]);
        }
    }
    for (int i = 0; i < joined.size(); i++) {
        cout << joined[i] << " \n"[i == joined.size() - 1];
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
