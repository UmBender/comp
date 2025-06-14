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
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    int off_set = 0;
    while (q--) {
        int type;
        cin >> type;
        switch (type) {
        case 1: {
            auto update_ap = [&](int pos, int x) {
                int real_pos = (pos - 1) + off_set;
                real_pos %= n;
                a[real_pos] = x;
            };
            int p, x;
            cin >> p >> x;
            update_ap(p, x);

        } break;
        case 2: {
            auto query = [&](int pos) -> int {
                int real_pos = (pos - 1) + off_set;
                real_pos %= n;
                return a[real_pos];
            };
            int p;
            cin >> p;
            cout << query(p) << endl;
        } break;
        case 3: {
            int k;
            cin >> k;
            auto update_k = [&](int k) {
                off_set += k;
                off_set %= n;
            };
            update_k(k);
        } break;
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
