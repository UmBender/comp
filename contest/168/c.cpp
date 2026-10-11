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
    vector<ll> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];
    vector<ll> a(n);

    vector<int> seted;
    for (int i = 0; i < n; i++) {
        if (b[i] != 0) seted.push_back(i);
    }

    if (seted.empty()) {
        for (int i = 0; i < n; i++) a[i] = i + 1;
    } else {
        int first = seted.front();
        a[first] = b[first];

        for (int i = first - 1; i >= 0; i--) { a[i] = a[i + 1] + 1; }

        for (int k = 1; k < (int)seted.size(); k++) {
            int l = seted[k - 1], r = seted[k];
            ll steps = r - l;
            ll diff = abs(b[r] - b[l]);

            if (diff > steps || (steps - diff) % 2 != 0) {
                cout << -1 << endl;
                return;
            }

            for (int i = l + 1; i <= r; i++) { a[i] = a[i - 1] + (a[i - 1] > b[r] ? -1 : 1); }
        }

        int last = seted.back();
        for (int i = last + 1; i < n; i++) { a[i] = a[i - 1] + 1; }
    }

    for (int i = 0; i < n; i++) { cout << a[i] << " \n"[i == n - 1]; }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
