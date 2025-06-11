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
    vector<int> a(m);
    for (auto &i : a) {
        cin >> i;
    }

    sort(a.begin(), a.end());
    vector<pair<int, int>> opt;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            opt.push_back({a[i / 2], a[m - 1 - i / 2]});
        } else {
            auto actual = opt.back();
            opt.push_back({actual.second, actual.first});
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            if (j % 2) {
                cout << opt[i].second << " \n"[j == 5];
            } else {
                cout << opt[i].first << " \n"[j == 5];
            }
        }
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
