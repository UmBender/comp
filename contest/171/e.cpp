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
using i128 = __int128;

void solve() {
    ll n;
    cin >> n;
    auto check = [&](ll a, ll d, ll len) -> bool {
        i128 prod = 1;
        for (int i = 0; i < len; i++) {
            i128 term = i128(a) + i128(i) * d;
            if (term > n) { return false; }
            prod *= term;
            if (prod > n) { return false; }
        }
        return true;
    };

    ll ans = 0;
    for (int len = 3; check(1, 1, len); len++) {
        ll mmax = n;
        for (ll a = 1; check(a, 1, len); a++) {
            ll l = 1, r = mmax;
            while (l < r) {
                ll mid = l + (r - l + 1) / 2;
                if (check(a, mid, len)) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            mmax = l;
            ans += mmax;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
