// clang-format off
//#include <atcoder/all>
#include <bits/stdc++.h>
#include <iostream>
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
//
int power3(int x) {
    return x * x * x;
}

int bs(int a, int b, int c) {
    // ax^2 + bx + c = 0の解
    int l = 0, r = 600000001;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (a * mid * mid + b * mid + c <= 0)
            l = mid;
        else
            r = mid;
    }
    if (a * l * l + b * l + c == 0)
        return l;
    return -1;
}

void solution() {
    int n;
    cin >> n;
    for (int i = 1; i * i * i <= n; i++) {
        if (n % i != 0) {
            continue;
        }
        int k = bs(3, 3 * i, i * i - n / i);
        if (k > 0) {
            cout << i + k << " " << k << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // atcoder::modint::set_mod(998244353);
    solution();

    return 0;
}
