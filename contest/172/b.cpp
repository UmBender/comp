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
using vvi = vector<ll>;
using pii = pair<ll, ll>;
using vii = vector<pii>;
using vvii = vector<vii>;

constexpr ll inf = 1LL << 60;
// nao usou vai e voalta, usou vai e volta,
// nao osou so vai, usou so vai

using State = array<array<ll, 2>, 2>;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<map<int, ll>> adj(n);
    vector<int> obr(n, 0);
    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        temp--;
        obr[temp] = 1;
    }
    for (int i = 0; i < n - 1; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u][v] = w;
        adj[v][u] = w;
    }

    vector<int> parent(n, -1);
    vector<int> order;
    order.push_back(0);
    for (int i = 0; i < n; i++) {
        int u = order[i];
        for (auto [v, w] : adj[u]) {
            if (v == parent[u]) continue;
            parent[v] = u;
            order.push_back(v);
        }
    }

    vector<State> dp(n);
    reverse(begin(order), end(order));
    for (int i = 0; i < n; i++) {
        int u = order[i];
        for (auto &row : dp[u]) row.fill(inf);
        dp[u][0][0] = 0;
        dp[u][1][0] = 0;
        for (auto [v, w] : adj[u]) {
            if (v == parent[u]) continue;
            if (!obr[v]) continue;
            obr[u] = true;
            State next;
            for (auto &row : next) row.fill(inf);
            for (int usedU = 0; usedU <= 1; usedU++) {
                for (int usedV = 0; usedU + usedV <= 1; usedV++) {
                    for (int freeEdge = 0; usedU + usedV + freeEdge <= 1; freeEdge++) {

                        int used = usedU + usedV + freeEdge;
                        ll cost = freeEdge ? 0 : w;

                        next[0][used] =
                            min(next[0][used], dp[u][0][usedU] + dp[v][0][usedV] + 2 * cost);

                        next[1][used] =
                            min(next[1][used], dp[u][1][usedU] + dp[v][0][usedV] + 2 * cost);

                        next[1][used] =
                            min(next[1][used], dp[u][0][usedU] + dp[v][1][usedV] + cost);
                    }
                }
            }

            dp[u] = next;
        }
    }
    cout << min(dp[0][1][0], dp[0][1][1]) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
