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
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) { cin >> a[i]; }
    vector<ll> reps(n);
    vector<ll> pref(n + 1);
    vector<ll> rangePref(n + 1);
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            reps[i] = 1;
        } else {
            reps[i] = reps[i - 1] + i + 1;
        }
        pref[i + 1] = pref[i] + a[i];
        rangePref[i + 1] = rangePref[i] + pref[i + 1];
    }
    auto sum = [&](ll x) -> ll {
        int full = upper_bound(reps.begin(), reps.end(), x) - reps.begin();

        ll used = (full == 0 ? 0LL : reps[full - 1]);
        ll remaining = x - used;

        return rangePref[full] + pref[remaining];
    };
    while (q--) {
        ll l, r;
        cin >> l >> r;
        cout << sum(r) - sum(l - 1) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
