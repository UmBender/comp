#include <bits/stdc++.h>

using namespace std;
using i32 = int;
using i64 = long long;
#define int i64
#define endl '\n'

vector<int> parent;
vector<int> longest;
vector<bool> acessed;
vector<vector<int>> adj;
int n, m;


void dfs(int actual) {
    acessed[actual] = true;
    parent[actual] = actual;

    for (int next : adj[actual]) {
        if (!acessed[next]) {
            dfs(next);
        }
        if (longest[actual] < longest[next] + 1) {
            longest[actual] = longest[next] + 1;
            parent[actual] = next;
        }
    }
}

signed main() {
    cin >> n >> m;
    parent = vector<int>(n, -1);
    longest = vector<int>(n, -1e9);
    acessed = vector<bool>(n);
    adj = vector<vector<int>>(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
    }
    longest[n - 1] = 0;

    dfs(0);

    if (!acessed[n - 1]) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    vector<int> sol;
    int actual = 0;
    while (actual != n - 1) {
        sol.push_back(actual);
        actual = parent[actual];
    }
    sol.push_back(n - 1);
    cout << sol.size() << endl;
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] + 1 << " \n"[i == sol.size() - 1];
    }

    return 0;
}
