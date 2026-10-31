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
    vector<ll> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) {
        if (i == 0 || i == n - 1) {
            ll dist = abs(x[0] - x[n - 1]) / 2;
            cout << dist << endl;
            continue;
        }
        ll mmin = 1e18;
        {
            // toright
            ll fdist = abs(x[i] - x[i + 1]) / 2;
            ll actual = x[i] + fdist;
            ll distLeft = abs(x[0] + fdist - actual) / 2;
            ll distRight = abs(x[n - 1] - fdist - actual) / 2;
            mmin = min(mmin, max(distLeft + fdist, distRight + fdist));
        }
        {
            // toleft
            ll fdist = abs(x[i] - x[i - 1]) / 2;
            ll actual = x[i] - fdist;
            ll distLeft = abs(x[0] + fdist - actual) / 2;
            ll distRight = abs(x[n - 1] - fdist - actual) / 2;
            mmin = min(mmin, max(distLeft + fdist, distRight + fdist));
        }
        cout << mmin << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
