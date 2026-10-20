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
constexpr int LOG = 32;

void solve() {
    int n;
    cin >> n;

    vector<array<int, LOG + 1>> bl(n);
    vector<array<int, LOG + 1>> hasRest(n);

    for (int v = 0; v < n; v++) {
        cin >> bl[v][1];
        bl[v][1]--;
    }

    for (int v = 0; v < n; v++) {
        int a;
        cin >> a;
        hasRest[v][1] = a;
    }

    for (int k = 2; k <= LOG; k++) {
        for (int v = 0; v < n; v++) {
            int middle = bl[v][k - 1];
            bl[v][k] = bl[middle][k - 1];
            hasRest[v][k] = hasRest[v][k - 1] || hasRest[middle][k - 1];
        }
    }

    vector<ll> cnt(n), can(n);

    for (int v = 0; v < n; v++) {
        int phase = bl[v][LOG];

        cnt[phase]++;
        can[phase] += hasRest[v][LOG];
    }

    ll ans = 0;

    for (int c = 0; c < n; c++) {
        if (cnt[c] == 0) continue;
        ans += cnt[c] * (cnt[c] - 1) / 2;
        int d = bl[c][1];
        if (c == d) continue;
        ans += cnt[c] * can[d];
        if (bl[d][1] == c && c < d) { ans -= can[c] * can[d]; }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
