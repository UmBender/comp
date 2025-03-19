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
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (auto &i : a) {
        cin >> i;
    }
    sort(a.begin(), a.end());
    vector<int> pref(n);
    int         actual = 0;
    for (int i = 1; i <= n; i++) {
        while (actual < a.size() && a[actual] < i) {
            actual++;
        }
        pref[i - 1] = m - actual;
    }
    for (auto i : pref) {
        cout << i << " ";
    }
    cout << endl;

    vector<int> prefix_sum(n + 1);

    for (int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + pref[i - 1];
    }
    for (auto i : prefix_sum) {
        cout << i << " ";
    }
    cout << endl;

    for (int i = 0; i < m; i++) {
        int actual = prefix_sum[n] - prefix_sum[max(0LL, m - a[i])];
        cout << "ACTUAL: " << actual << " I: " << i << endl;
    }

    int counter = 0;
    cout << counter << endl;
}

int32_t main() {
    // atcoder::modint::set_mod(998244353);
    int t;
    cin >> t;
    while (t--)
        solution();

    return 0;
}
