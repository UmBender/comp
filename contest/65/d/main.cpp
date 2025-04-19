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
    vector<pair<int, int>> elements(n);
    for (auto &[i, j] : elements) {
        cin >> i >> j;
        i = -i;
    }
    set<pair<int, int>> xy;
    for (int i = 0; i < n; i++) {
        xy.insert(elements[i]);
    }
    map<int, int> columns;
    for (int i = 0; i < n; i++) {
        columns[elements[i].first]++;
    }
    int correct_column;
    for (auto [i, j] : columns) {
        if (j & 1) {
            correct_column = i;
            break;
        }
    }
    int           correct_diagonal;
    map<int, int> diagonal;
    for (int i = 0; i < n; i++) {
        diagonal[elements[i].first - elements[i].second]++;
    }
    for (auto [i, j] : diagonal) {
        if (j & 1) {
            correct_diagonal = i;
            break;
        }
    }
    cout << -correct_column << " " << correct_column - correct_diagonal << endl;
}
void solution1() {

    int n;
    cin >> n;
    vector<pair<int, int>> elements(n);
    for (auto &[i, j] : elements) {
        cin >> i >> j;
        i = -i;
    }
    set<pair<int, int>> xy;
    for (int i = 0; i < n; i++) {
        xy.insert(elements[i]);
    }
    while (xy.size() > 1) {
        auto ff         = xy.begin();
        auto [xl1, yl1] = *ff;
        ff++;
        auto [xl2, yl2] = *ff;
        if (xl1 == xl2) {
            vector<pair<int, int>> arr = {{xl1, yl1},
                                          {xl1, yl1 + 1},
                                          {xl1 + 1, yl1 + 1},
                                          {xl1 + 1, yl1 + 2}};
            for (auto [x, y] : arr) {
                if (xy.count({x, y})) {
                    xy.erase({x, y});
                } else {
                    xy.insert({x, y});
                }
            }
            continue;
        }

        auto ee = xy.end();
        ee--;
        auto [xr1, yr1] = *ee;
        ee--;
        auto [xr2, yr2]            = *ee;

        vector<pair<int, int>> arr = {
            {xr1, yr1}, {xr1, yr1 - 1}, {xr1 - 1, yr1 - 1}, {xr1 - 1, yr1 - 2}};
        for (auto [x, y] : arr) {
            if (xy.count({x, y})) {
                xy.erase({x, y});
            } else {
                xy.insert({x, y});
            }
        }
    }
    auto [x, y] = *xy.begin();
    cout << -x << " " << y << endl;
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
