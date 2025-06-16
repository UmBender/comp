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

int bs(int coef, int mmax, int base) {
    int l          = 0;
    int r          = MAX_INT;
    int maxx_value = 0;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (mmax - (coef) * (m - 1) >= base) {
            maxx_value = max(m, maxx_value);
            l          = m + 1;
        } else {
            r = m - 1;
        }
    }
    return maxx_value;
}

void solution() {
    int k, a, b, x, y;
    cin >> k >> a >> b >> x >> y;
    if (a < b) {
        swap(x, y);
        swap(a, b);
    }
    // vale a pena usar x e y
    if (x < y) {
        int diff_a    = k - a;
        int counter_a = 0;
        if (diff_a >= 0) {
            counter_a = 1 + (diff_a) / x;
        }
        int actual_k  = k - counter_a * x;
        int diff_b    = actual_k - b;
        int counter_b = 0;
        if (diff_b >= 0) {
            counter_b = 1 + (diff_b) / y;
        }
        cout << counter_b + counter_a << endl;

    } else {
        int actual_k  = k;
        int diff_b    = actual_k - b;
        int counter_b = 0;
        if (diff_b >= 0) {
            counter_b = 1 + (diff_b) / y;
        }
        cout << counter_b << endl;
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
