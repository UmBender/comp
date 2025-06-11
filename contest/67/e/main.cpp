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
    int n, q;
    cin >> n >> q;
    vector<int> p(n);
    vector<int> value_to_pos(n + 1);
    for (auto &i : p) {
        cin >> i;
    }
    vector<pair<pair<int, int>, int>> quer(q);
    for (auto &i : quer) {
        cin >> i.first.first >> i.first.second >> i.second;
    }
    for (int i = 0; i < n; i++) {
        value_to_pos[p[i]] = i;
    }

    vector<vector<int>> pref(n + 1, vector<int>(ceil(sqrt(n))));
    for(int i = 0; i < n;i++) {
        

    }
    for (int qq = 0; qq < q; qq++) {
        auto [lr, x] = quer[qq];
        auto [l, r]  = lr;
        if (value_to_pos[x] + 1 < l || value_to_pos[x] + 1 > r) {
            cout << -1 << " ";
            continue;
        }
        vector<pair<int, bool>> path;
        l--, r--;
        while (l <= r) {
            int m = (l + r) / 2;
            if (m == value_to_pos[x]) {
                break;
            }
            if (m > value_to_pos[x]) {
                path.push_back({m, p[m] < x});
                r = m - 1;
            } else {
                path.push_back({m, p[m] > x});
                l = m + 1;
            }
        }
        int bigger       = 0;
        int smaller      = 0;
        int need_bigger  = 0;
        int need_smaller = 0;
        for (auto [pos, need] : path) {
            if (p[pos] > x) {
                bigger++;
                need_bigger += need;
            } else {
                smaller++;
                need_smaller += need;
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
    while (t--) {
        solution();
        cout << endl;
    }

    return 0;
}
