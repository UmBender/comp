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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) { cin >> a[i]; }
    ll cnt = 0;
    ll in = 0;

    for (int i = 0; i < n - 1; i++) {
        ll begin = min(a[i], a[i + 1]);
        ll end = max(a[i], a[i + 1]);
        if (begin <= k && k <= end) { in++; }
    }
    for (int i = 1; i < n - 1; i++) {
        if (a[i] == k) { cnt++; }
    }

    cout << in - cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
