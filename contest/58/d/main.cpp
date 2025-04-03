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
int bs(int row_size, int block) {
    int l = 1;
    int r = 1E9 + 100;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (row_size - (block * (m - 1) + (m - 1)) <= block &&
            row_size - (block * (m - 1) + (m - 1)) >= 0) {
            int rest = row_size - block * (m - 1) - (m - 1);
            return rest + block * (m - 1);
        }
        if (row_size - (block * (m - 1) + (m - 1)) > block) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return -1;
}

int sbs(int row_size, int n_rows, int k) {
    int l = 1;
    int r = row_size;
    while (l <= r) {
        int m      = l + (r - l) / 2;
        int result = bs(row_size, m);
        if (m == 1) {
            if (result * n_rows >= k) {

                return m;
            } else {
                l = m + 1;
            }
            continue;
        }
        int lower = bs(row_size, m - 1);
        if (result * n_rows >= k && lower * n_rows < k) {
            return m;
        }
        if (result * n_rows < k) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return -1;
}

void solution() {
    int n, m, k;
    cin >> n >> m >> k;
    cout << sbs(m, n, k) << endl;
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
