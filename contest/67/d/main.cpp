// clang-format off
//#include <atcoder/all>
#include <bits/stdc++.h>
#include <ostream>
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
    vector<int> a(n), b(m);
    for (auto &i : a) {
        cin >> i;
    }
    for (auto &i : b) {
        cin >> i;
    }
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] >= b[j]) {
            i++, j++;
        } else {
            i++;
        }
    }
    if (j == m) {
        cout << 0 << endl;
        return;
    }
    vector<int> front(n + 1), back(n + 1);
    int         actual = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= b[actual]) {
            front[i] = actual;
            actual++;
        } else {
            front[i] = actual;
        }
    }
    front[n] = actual;
    actual   = m - 1;
    for (int i = n; i > 0; i--) {
        if (a[i - 1] >= b[actual]) {
            back[i] = actual;
            actual--;
        } else {
            back[i] = actual;
        }
    }
    back[0] = actual;
    /*
    cout << "NAO DEU" << endl;
    for (int i = 0; i < n + 1; i++) {
        cout << front[i] << " \n"[i == n];
    }
    for (int i = 0; i < n + 1; i++) {
        cout << back[i] << " \n"[i == n];
    }
    cout << "END" << endl;
    */

    int mmin = MAX_INT;
    for (int i = 0; i <= n; i++) {
        if (front[i] == back[i]) {
            mmin = min(mmin, b[front[i]]);
        }
    }
    if (mmin == MAX_INT) {
        cout << -1 << endl;
        return;
    }
    cout << mmin << endl;
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
