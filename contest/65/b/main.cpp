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
    vector<int> l(n), r(n);
    for (auto &i : l) {
        cin >> i;
    }
    for (auto &i : r) {
        cin >> i;
    }

    int actual = 0;
    vector<int> mmin(n);
    vector<int> mmax(n);
    for (int i = 0; i < n; i++) {
        mmin[i] = min(l[i], r[i]);
        mmax[i] = max(l[i], r[i]);
        actual += mmax[i];
    }
    sort(mmin.rbegin(), mmin.rend());
    int i = 0;
    while(k > 1) {
        actual += mmin[i];
        i++;
        k--;
    }
    actual++;
    cout << actual << endl;

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
