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
    string s;
    cin >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            a[i] = 1;
        } else {
            a[i] = 0;
        }
    }

    int ones  = 0;
    int zeros = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            zeros++;
        } else {
            ones++;
        }
    }
    int dif           = abs(ones - zeros);
    int possible      = 0;
    int minimal_pairs = dif / 2;
    if (ones > zeros) {
        possible = ones - dif;
    } else {
        possible = zeros - dif;
    }
    if (k % 2 == minimal_pairs % 2 && k >= minimal_pairs) {
        k -= minimal_pairs;
        if (possible >= k) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        cout << "NO" << endl;
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
