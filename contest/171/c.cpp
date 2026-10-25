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

    ll n, k, t;
    cin >> n >> k >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(begin(a), end(a));
    ll ans = (a[0] != 0);
    ll last = 0;
    for (ll x : a) {
        if (x > t) { continue; }
        if (x > last) { ans += (x - last - 1) / k; }
        last = x;
    }
    if (last < t) { ans += (t - last - 1) / k; }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
