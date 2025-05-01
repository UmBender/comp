// clang-format off
//#include <atcoder/all>
#include <bit>
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
    int n, x;
    cin >> n >> x;
    if (n == 1) {
        if (x == 0) {
            cout << -1 << endl;
        } else {
            cout << x << endl;
        }
        return;
    }
    if (x == 0) {
        if (n % 2 == 0) {
            cout << n << endl;
        } else {
            cout << 3 + n << endl;
        }
        return;
    }
    int counter = __builtin_popcount(x);
    if (counter >= n) {
        cout << x << endl;
        return;
    }
    if (n == 2) {
        if (x == 1) {
            cout << 5 << endl;
            return;
        }
        cout << x + 2 << endl;
        return;
    }
    int empty = n - counter;
    if (empty % 2 == 0) {
        cout << x + empty << endl;
        return;
    }
    cout << x + empty + 1 << endl;
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
