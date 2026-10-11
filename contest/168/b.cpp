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
    int n;
    cin >> n;
    map<ll, ll> mp;
    for (int i = 0; i < n; i++) {
        ll ci, pi;
        cin >> ci >> pi;
        if (mp.count(ci)) {
            mp[ci] = min(mp[ci], pi);
        } else {
            mp[ci] = pi;
        }
    }
    ll total = 0;
    for (auto [k, v] : mp) { total += v; }
    cout << total << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
