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
    vector<int> d(n);
    for (auto &i : d) {
        cin >> i;
    }
    vector<pair<int, int>> lr(n);
    for (auto &[l, r] : lr) {
        cin >> l >> r;
    }
    vector<pair<int, int>> minmax(n);
    if (d[0] == -1) {
        minmax[0].first  = 0;
        minmax[0].second = 1;
    } else {
        minmax[0].first  = d[0];
        minmax[0].second = d[0];
    }
    minmax[0].first  = max(minmax[0].first, lr[0].first);
    minmax[0].second = min(minmax[0].second, lr[0].second);
    if (minmax[0].first > minmax[0].second) {
        cout << -1 << endl;
        return;
    }

    for (int i = 1; i < n; i++) {
        if (d[i] == -1) {
            minmax[i].first  = minmax[i - 1].first;
            minmax[i].second = minmax[i - 1].second + 1;
        } else {
            minmax[i].first  = minmax[i - 1].first + d[i];
            minmax[i].second = minmax[i - 1].second + d[i];
        }
        minmax[i].first  = max(minmax[i].first, lr[i].first);
        minmax[i].second = min(minmax[i].second, lr[i].second);
        if (minmax[i].first > minmax[i].second) {
            cout << -1 << endl;
            return;
        }
    }
    vector<int> result = d;

    int pos            = minmax.back().second;

    for (int i = n - 1; i >= 1; i--) {
        if (result[i] == -1) {
            if (minmax[i - 1].second < pos) {
                result[i] = 1;
            } else {
                result[i] = 0;
            }
        }
        pos -= result[i];
    }

    if (result[0] == -1) {
        if (pos == 1 && minmax[0].second == 1) {
            result[0] = 1;
        } else {
            result[0] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << " \n"[i == n - 1];
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
