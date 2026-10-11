#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
template <typename... T> void _dbg(const char *names, T &&...args) {
    cerr << "[" << names << "] =";
    ((cerr << ' ' << args), ...);
    cerr << endl;
}
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...)
#endif

using ll = long long;

ll phi(ll x) {
    ll result = x;
    if (x % 2 == 0) {
        result -= result / 2;
        while (x % 2 == 0) { x /= 2; }
    }
    for (ll p = 3; p * p <= x; p += 2) {
        if (x % p != 0) continue;
        result -= result / p;
        while (x % p == 0) { x /= p; }
    }
    if (x > 1) result -= result / x;
    return result;
}

void solve() {
    ll n;
    cin >> n;
    ll first = phi(2 * n + 3);
    ll second = phi(2 * n + 4);

    cout << (first + second) / 2 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
