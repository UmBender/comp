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

int big_power(int x) {
    int i = 1;
    while (i * 2 <= x) {
        i *= 2;
    }
    return i;
}
void solution() {
    int l, r;
    cin >> l >> r;
    int big_differ = big_power(l ^ r);

    int repost     = 2 * big_differ - 1;
    repost         = ~repost;
    int init       = r & repost;
    int a = init, b = init;
    a |= big_differ;
    b |= (big_differ - 1);
    int c = -1;
    for (int i = l; i <= r; i++) {
        if (i != a && i != b) {
            c = i;
            break;
        }
    }
    cout << a << ' ' << b << ' ' << c  << endl;
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
