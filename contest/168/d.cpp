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
using vi = vector<ll>;

void solve() {
    int n;
    cin >> n;
    vi a(n), pref(n + 1);
    for (int i = 0; i < n; i++) { cin >> a[i]; }
    for (int i = 0; i < n; i++) { pref[i + 1] = pref[i] + a[i]; }
    map<ll, ll> vals;
    ll mmin = 1e18;
    for (int i = 0; i <= n; i++) { vals[pref[i]]++; }
    for (int i = 0; i < n; i++) {
        vals[pref[i]]--;
        if (vals[pref[i]] == 0) { vals.erase(pref[i]); }
        auto it = vals.lower_bound(pref[i]);
        if (it != vals.end()) { mmin = min(mmin, abs(it->first - pref[i])); }
        if (it != vals.begin()) {
            it--;
            mmin = min(mmin, abs(it->first - pref[i]));
        }
    }
    cout << mmin << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
