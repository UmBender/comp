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
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }

    sort(a.begin(), a.end());
    int max_left  = MAX_INT;
    int max_right = 0;
    if ((n - k) % 2 == 1) {
        int leftl  = 0;
        int leftr  = n - k - 1;
        int leftm  = (leftl + leftr) / 2;
        max_left   = a[leftm];
        int rightl = k;
        int rightr = n - 1;
        int rightm = (rightl + rightr) / 2;
        max_right  = a[rightm];
    } else {
        int leftl  = 0;
        int leftr  = n - k - 1;
        int leftm  = (leftl + leftr) / 2;
        max_left   = a[leftm];
        int rightl = k;
        int rightr = n - 1;
        int rightm = (rightl + rightr + 1) / 2;
        max_right  = a[rightm];
    }
/*
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
         */
    cout << max_right - max_left + 1 << endl;
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
