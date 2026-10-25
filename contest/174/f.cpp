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
constexpr ll MOD = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].emplace_back(b, c);
    }

    vector<ll> ans(n);
    vector<bool> seen(n, false);
    queue<vector<ll>> q;
    q.push(vector<ll>{0});
    seen[0] = true;

    while (!q.empty()) {
        vector<ll> group = q.front();
        q.pop();

        vector<vector<ll>> bucket(10);

        for (int u : group) {
            for (auto [v, c] : adj[u]) {
                if (!seen[v]) { bucket[c].push_back(v); }
            }
        }

        for (int c = 1; c <= 9; c++) {
            vector<ll> next;
            ll val = (ans[group[0]] * 10 + c) % MOD;

            for (ll v : bucket[c]) {
                if (seen[v]) { continue; }

                seen[v] = true;
                ans[v] = val;
                next.push_back(v);
            }

            if (!next.empty()) { q.push(next); }
        }
    }
    for (int i = 1; i < n; i++) { cout << ans[i] << endl; }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
