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
vector<vector<int>>           grid(700, vector<int>(700));
map<int, set<pair<int, int>>> by_dist;
map<int, set<pair<int, int>>> not_used;

void set_grid() {
    int actual = 1LL;
    for (int i = 0; i < 700; i++) {
        grid[i][0] = actual;
        if (i % 2 == 0) {
            actual++;
        } else {
            actual += 2LL;
        }
    }
    actual = 1LL;
    for (int i = 0; i < 700; i++) {
        grid[0][i] = actual;
        if (i % 2 == 0) {
            actual++;
        } else {
            actual += 2LL;
        }
    }
    for (int i = 1; i < 700; i++) {
        for (int j = 1; j < 700; j++) {
            if (grid[i - 1][j - 1] == grid[i - 1][j] &&
                grid[i - 1][j] == grid[i][j - 1]) {
                grid[i][j] = grid[i - 1][j - 1] + 2;
                continue;
            }
            if (grid[i - 1][j - 1] != grid[i - 1][j] &&
                grid[i - 1][j] == grid[i][j - 1]) {
                grid[i][j] = grid[i - 1][j] + 3;
                continue;
            }
            grid[i][j] =
                max(grid[i - 1][j - 1], max(grid[i - 1][j], grid[i][j - 1]));
        }
    }
    for (int i = 0; i < 700; i++) {
        for (int j = 0; j < 700; j++) {
            if (i % 2 == 0 && j % 2 == 0) {
                not_used[grid[i][j]].insert(make_pair(
                    3LL * (i / 2) + 1 + i % 2, 3LL * (j / 2) + 1 + j % 2));
            }
            by_dist[grid[i][j]].insert(make_pair(3LL * (i / 2) + 1 + i % 2,
                                                 3LL * (j / 2) + 1 + j % 2));
        }
    }
}
void solution() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    map<int, set<pair<int, int>>> used;
    map<int, set<pair<int, int>>> unique;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            auto &[j, _] = *by_dist.begin();
            auto xy      = *by_dist[j].begin();
            used[j].insert(xy);
            by_dist[j].erase(xy);
            if (by_dist[j].empty()) {
                by_dist.erase(j);
            }
            cout << xy.first << " " << xy.second << endl;
            if (not_used.count(j)) {
                if (not_used[j].count(xy)) {
                    unique[j].insert(xy);
                    not_used[j].erase(xy);
                    if (not_used[j].empty()) {
                        not_used.erase(j);
                    }
                }
            }
        } else {
            auto &[j, _] = *not_used.begin();
            auto xy      = *not_used[j].begin();
            not_used[j].erase(xy);
            unique[j].insert(xy);
            used[j].insert(xy);
            if (not_used[j].empty()) {
                not_used.erase(j);
            }
            by_dist[j].erase(xy);
            if (by_dist[j].empty()) {
                by_dist.erase(j);
            }
            cout << xy.first << " " << xy.second << endl;
        }
    }
    for (auto &[i, j] : used) {
        for (auto k : j) {
            if (k.first % 3 == 1 && k.second % 3 == 1) {
                if (not_used[i].count(k) == 0)
                    not_used[i].insert(k);
            }
            if (by_dist[i].count(k) == 0)
                by_dist[i].insert(k);
        }
    }
    for (auto &[i, j] : unique) {
        for (auto k : j) {
            if (not_used[i].count(k) == 0)
                not_used[i].insert(k);
            if (by_dist[i].count(k) == 0)
                by_dist[i].insert(k);
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // atcoder::modint::set_mod(998244353);
    set_grid();
    int t;
    cin >> t;
    while (t--)
        solution();

    return 0;
}
