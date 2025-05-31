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

struct BIT {
    vector<int> a;
    vector<int> t;
    BIT(int n) : a(n), t(n + 1) {}
    void update(int pos, int value) {
        for (++pos; pos < t.size(); pos += pos & -pos) {
            t[pos] += value;
        }
    }
    void updaterange(int l, int r, int value) {
        update(l, value);
        update(r + 1, -value);
    }

    int q(int pos) {
        int acc = 0;
        pos++;
        for (; pos > 0; pos -= (-pos & pos)) {
            acc += t[pos];
        }
        return acc;
    }
    int query(int pos) { return q(pos); }
};

void solution() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> lr(m);
    BIT                    bit(n);

    for (auto &i : lr) {
        cin >> i.first >> i.second;
    }
    for (auto [l, r] : lr) {
        l--;
        r--;
        bit.updaterange(l, r, 1);
    }

    int mmin = MAX_INT;
    for (int i = 0; i < n; i++) {
        mmin = min(mmin, bit.query(i));
    }
    cout << mmin << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // atcoder::modint::set_mod(998244353);
    solution();

    return 0;
}
