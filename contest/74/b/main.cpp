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

int row_top(int n, int m, int a, int b) {
    int iters = 0;
    n         = a;
    iters++;
    while (n > 1 || m > 1) {
        if (n > 1) {
            int middle = (n + 1) / 2;
            iters++;
            n = middle;

        } else {
            int middle = (m + 1) / 2;
            iters++;
            m = middle;
        }
    }
    return iters;
}
int row_bot(int n, int m, int a, int b) {
    int iters = 0;
    n         = n - a + 1;
    iters++;
    while (n > 1 || m > 1) {
        if (n > 1) {
            int middle = (n + 1) / 2;
            iters++;
            n = middle;

        } else {
            int middle = (m + 1) / 2;
            iters++;
            m = middle;
        }
    }
    return iters;
}
int col_left(int n, int m, int a, int b) {
    int iters = 0;
    m         = m - b + 1;
    iters++;
    while (n > 1 || m > 1) {
        if (n > 1) {
            int middle = (n + 1) / 2;
            iters++;
            n = middle;

        } else {
            int middle = (m + 1) / 2;
            iters++;
            m = middle;
        }
    }
    return iters;
}
int col_right(int n, int m, int a, int b) {
    int iters = 0;
    m         = b;
    iters++;
    while (n > 1 || m > 1) {
        if (n > 1) {
            int middle = (n + 1) / 2;
            iters++;
            n = middle;

        } else {
            int middle = (m + 1) / 2;
            iters++;
            m = middle;
        }
    }
    return iters;
}
void solution() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int minimal = MAX_INT;
    minimal     = min(minimal, col_right(n, m, a, b));
    minimal     = min(minimal, col_left(n, m, a, b));
    minimal     = min(minimal, row_bot(n, m, a, b));
    minimal     = min(minimal, row_top(n, m, a, b));

    cout << minimal << endl;
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
