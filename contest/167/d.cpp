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

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> l(n, 1e15), r(n, 1e15);
    for (int i = 1; i < n; i++) cin >> l[i];
    for (int i = 0; i < n - 1; i++) cin >> r[i];
    {
        // newRights
        ll mmin = r[0];
        for (int i = 0; i < n; i++) {
            mmin = min(r[i], mmin);
            r[i] = min(r[i], mmin + l[i]);
        }
    }
    {
        // newLefts
        ll mmin = l[n - 1];
        for (int i = n - 1; i >= 0; i--) {
            mmin = min(l[i], mmin);
            l[i] = min(l[i], mmin + r[i]);
        }
    }

    for (int qq = 0; qq < q; qq++) {
        ll in, out;
        cin >> in >> out;
        in--, out--;
        cout << (in < out ? r[in] : l[in]) << endl;
    }
}
