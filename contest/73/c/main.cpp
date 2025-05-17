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
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto &i : p) {
        cin >> i;
    }
    int counter      = 0;
    int actual_begin = 0;
    int begin_inflex = 0;
    int end_inflex   = 0;
    int actual_end   = 0;
    while (actual_begin < n - 3) {
        if (p[actual_begin] < p[actual_begin + 1]) {
            begin_inflex = actual_begin;
            while (begin_inflex < n - 3 &&
                   !(p[begin_inflex] < p[begin_inflex + 1] &&
                     p[begin_inflex + 1] > p[begin_inflex + 2])) {
                begin_inflex++;
            }
            if (begin_inflex >= n - 3 ||
                !(p[begin_inflex] < p[begin_inflex + 1] &&
                  p[begin_inflex + 1] > p[begin_inflex + 2])) {
                break;
            }
            end_inflex = begin_inflex + 2;
            while (end_inflex < n && !(p[end_inflex - 1] < p[end_inflex] &&
                                       p[end_inflex - 1] < p[end_inflex - 2])) {
                end_inflex++;
            }
            if (end_inflex >= n || !(p[end_inflex - 1] < p[end_inflex] &&
                                     p[end_inflex - 1] < p[end_inflex - 2])) {
                break;
            }
            actual_end = end_inflex;
            while (actual_end < n - 1 && p[actual_end] < p[actual_end + 1]) {
                actual_end++;
            }
            counter += (begin_inflex - actual_begin + 1) *
                       (actual_end - end_inflex + 1);
            actual_begin = end_inflex - 1;
        } else {
            actual_begin++;
        }
    }

    cout << counter << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // atcoder::modint::set_mod(998244353);
    solution();

    return 0;
}
