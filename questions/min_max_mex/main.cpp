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
    int n, k;
    cin >> n >> k;
    vector<int>   a(n);
    map<int, int> counter;
    for (auto &i : a) {
        cin >> i;
        counter[i]++;
    }
    int maxx = -1;
    for (auto [i, j] : counter) {
        if (j >= k) {
            maxx = i;
        }
    }
    int l         = 0;
    int r         = maxx;
    int maxx_okay = -1;
    while (l <= r) {
        int          m      = l + (r - l) / 2;
        int          solved = 0;
        vector<bool> ncounter(m + 1, 0);
        int          number_actual = 0;
        for (int i = 0; i < n; i++) {
            if (number_actual == m + 1) {
                solved++;
                fill(ncounter.begin(), ncounter.end(), false);
                number_actual = 0;
            }
            if (a[i] > m) {
                continue;
            }
            if (!ncounter[a[i]]) {
                ncounter[a[i]] = true;
                number_actual++;
            }
        }
        if (number_actual == m + 1) {
            solved++;
        }

        if (solved >= k) {
            maxx_okay = max(m, maxx_okay);
            l         = m + 1;
        } else {
            r = m - 1;
        }
    }
    cout << maxx_okay + 1 << endl;
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
