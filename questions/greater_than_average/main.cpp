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

int pos(vector<int> &a, int sum, int mult) {
    int l = 0, r = a.size() - 1;
    int actual = -1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (a[m] * mult <= sum) {
            actual = max(m, actual);
            l      = m + 1;
        } else {
            r = m - 1;
        }
    }
    return actual;
}
void solution() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    sort(a.begin(), a.end());

    int sum  = 0;
    int maxx = 0;
    for (int i = 0; i < n; i++) {
        sum += static_cast<int>(a[i]);
        int fpos = pos(a, sum, i + 1);
        if (fpos == -1) {
            continue;
        }
        maxx = max(maxx, i - fpos);
    }
    cout << maxx << endl;
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
