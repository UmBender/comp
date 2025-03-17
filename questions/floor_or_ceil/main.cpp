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
    int x, n, m;
    cin >> x >> n >> m;
    int biggest  = x;
    int smallest = x;
    for (int i = 0; i < n && i < 64; i++) {
        biggest /= 2;
    }

    for (int i = 0; i < m && i < 64; i++) {
        if (biggest % 2) {
            biggest /= 2;
            biggest += 1;
        } else {
            biggest /= 2;
        }
    }
    if (n == 0) {
        for (int i = 0; i < m && i < 64; i++) {
            if (smallest % 2) {
                smallest /= 2;
                smallest += 1;
            } else {
                smallest /= 2;
            }
        }
    } else {
        for (int i = 0; i < m && i < 64; i++) {
            if (smallest % 2) {
                smallest /= 2;
                smallest += 1;
            } else {
                smallest /= 2;
            }
        }
        for (int i = 0; i < n && i < 64; i++) {
            smallest /= 2;
        }
    }
    cout << smallest << " " << biggest << endl;
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
