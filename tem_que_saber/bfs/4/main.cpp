#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vvii = vector<vii>;

constexpr int inf = 1e9 + 100;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--, t--;
    vvi adj(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
    }
    vvi revs(n);
    vi dists(n, inf);
    vi used(n);
    queue<pii> qq;
    qq.push(make_pair(s, 0));
    dists[s] = 0;
    while (!qq.empty()) {
        auto [actual, dist] = qq.front();
        qq.pop();
        if (used[actual]) continue;
        used[actual] = 1;
        for (int next : adj[actual]) {
            if (dists[next] <= dist || used[next]) { continue; }
            if (dist + 1 < dists[next]) {
                revs[next].clear();
                qq.push(make_pair(next, dist + 1));
                dists[next] = dist + 1;
            }
            revs[next].push_back(actual);
        }
    }

    vi ans(n);
    set<int> actuals = {t}, next;
    while (!actuals.empty()) {
        for (int actual : actuals) {
            for (int backs : revs[actual]) { next.insert(backs); }
            ans[actual] = 1;
            if (actuals.size() == 1) { ans[actual] = 2; }
        }
        swap(next, actuals);
        next.clear();
    }

    if (dists[t] == inf) {
        cout << -1 << endl;
        return 0;
    }
    ans[s] = 2;
    cout << dists[t] << endl;
    for (int i = 0; i < n; i++) { cout << ans[i] << " \n"[i == n - 1]; }

    return 0;
}
