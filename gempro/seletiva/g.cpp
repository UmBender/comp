#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using i64 = long long;
#define int i64
const int MAX = 1e9;
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> minimal(n + 1, MAX);
    auto calc = [&](int actual) -> int {
        struct Node {
            int actual;
            int last;
            int length;
        };
        vector<int> minis(n + 1, MAX);
        queue<Node> nodes;
        for (int next : adj[actual]) {
            minis[next] = 1;
            nodes.push({next, actual, 1});
        }
        while (!nodes.empty()) {
            Node actual_node = nodes.front();
            nodes.pop();

            for (int next : adj[actual_node.actual]) {
                if (next == actual_node.last) {
                    continue;
                }
                if (minis[next] != MAX) {
                    minis[actual] = min(minis[next] + actual_node.length + 1,
                                        minis[actual]);
                    continue;
                }

                minis[next] = actual_node.length + 1;
                nodes.push({next, actual_node.actual, actual_node.length + 1});
            }
        }
        return minis[actual];
    };

    for (int i = 1; i <= n; i++) {
        minimal[i] = calc(i);
    }
    int mmin = MAX;

    for (int i = 1; i <= n; i++) {
        mmin = min(mmin, minimal[i]);
    }
    if (mmin == MAX) {
        mmin = -1;
    }
    cout << mmin << endl;
    return 0;
}
