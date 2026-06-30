#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); i++)
mt19937 rng(random_device{}());

#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;

    vector<int> p(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> c[i];
    }

    vector<pair<int, int>> req(m);
    for (int i = 0; i < m; i++) {
        cin >> req[i].fi >> req[i].se;
        req[i].fi--;
        req[i].se--;
    }

    ll max_val = 0;

    for (int mask = 0; mask < (1 << n); mask++) {
        bool valid = true;

        for (auto &edge : req) {
            int u = edge.first;
            int v = edge.second;

            if (((mask >> u) & 1) && !((mask >> v) & 1)) {
                valid = false;
                break;
            }
        }

        if (valid) {
            int current_val = 0;
            for (int i = 0; i < n; i++) {
                if ((mask >> i) & 1) {
                    current_val += p[i] - c[i];
                }
            }
            max_val = max(max_val, current_val);
        }
    }

    cout << max_val << endl;

    return 0;
}
