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
    vector<string> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    vector<vector<string>> b(m, vector<string>(n));
    for (auto &i : b) {
        for (auto &j : i) {
            cin >> j;
        }
    }

    vector<bool> is_build(n, false);
    for (int i = 0; i < n; i++) {
        if (is_build[i]) {
            continue;
        }
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j][i]) {
                is_build[i] = true;
                break;
            }
        }
    }
    bool actual = true;
    for (auto i : is_build) {
        actual = actual && i;
    }
    if (!actual) {
        cout << -1 << endl;
        return;
    }
    vector<pair<int, int>> points(m);
    for (int i = 0; i < m; i++) {
        points[i] = {0, i};
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j][i]) {
                points[j].first++;
            }
        }
    }
    sort(points.rbegin(), points.rend());
    cout << n + 2 * (n - points.front().first) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // atcoder::modint::set_mod(998244353);
    int t;
    cin >> t;
    while (t--) {
        solution();
    }

    return 0;
}
