#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using i64 = long long;
#define int i64
#define endl '\n'

signed main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    map<pair<int, int>, int> cost;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].push_back(b);
        pair<int, int> ab = {a, b};
        if (cost.count(ab)) {
            cost[ab] = min(c, cost[ab]);
        } else {
            cost[ab] = c;
        }
    }
    vector<int> minNo(n, 1e17), minTick(n, 1e17);

    set<tuple<int, int, int>> pq;

    pq.insert({0, 0, 0});
    while (!pq.empty()) {
        auto [path, opt, node] = *pq.begin();
        pq.erase({path, opt, node});

        for (auto to : adj[node]) {
            int pCost = cost[make_pair(node, to)];
            if (opt == 0) {
                if (minNo[to] > path + pCost) {
                    pq.erase({minNo[to], 0, to});
                    minNo[to] = path + pCost;
                    pq.insert({minNo[to], 0, to});
                }

                if (minTick[to] > path + pCost / 2) {
                    pq.erase({minTick[to], 1, to});
                    minTick[to] = path + pCost / 2;
                    pq.insert({minTick[to], 1, to});
                }
            }
            if (opt == 1) {
                if (minTick[to] > path + pCost) {
                    pq.erase({minTick[to], 1, to});
                    minTick[to] = path + pCost;
                    pq.insert({minTick[to], 1, to});
                }
            }
        }
    }
    cout << min(minTick[n - 1], minNo[n - 1]) << endl;

    return 0;
}
