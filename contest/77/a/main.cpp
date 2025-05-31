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

int sqrtd(int value) {
    int l = 0, r = 1E5;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (m * m == value) {
            return m;
        }
        if (m * m < value) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return -1;
}
void solution() {
    int sum;
    cin >> sum;
    int value = sqrtd(sum);
    if (value == -1) {
        cout << -1 << endl;
    } else {
        cout << value << " " << 0 << endl;
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
