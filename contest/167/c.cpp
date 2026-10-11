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

void solve() {
    ll n, w;
    cin >> n >> w;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) { cin >> a[i] >> b[i]; }
    ll mmax = 0;
    for (ll bits = 0; bits < (1ll << n); bits++) {
        ll temp = bits;
        ll acc = 0, vol = 0;
        for (ll i = 0; i < n; i++) {
            if (temp & 1) {
                acc += a[i];
                vol += b[i];
            }
            temp /= 2ll;
        }
        if (vol <= w) { mmax = max(acc, mmax); }
    }
    cout << mmax << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
