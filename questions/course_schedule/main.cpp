#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using i64 = long long;
#define int i64
#define endl '\n'

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<vector<int>> rev(n);
    vector<int> leafs, counter(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        rev[b].push_back(a);
        counter[a]++;
    }
    int rest = n;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (counter[i] == 0) {
            leafs.push_back(i);
            ans.push_back(i);
            rest--;
        }
    }
    while (!leafs.empty()) {
        int actual = leafs.back();
        leafs.pop_back();
        for (int back : rev[actual]) {
            counter[back]--;
            if (counter[back] == 0) {
                leafs.push_back(back);
                ans.push_back(back);
                rest--;
            }
        }
    }
    if (rest) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    reverse(ans.begin(), ans.end());
    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << " \n"[i == n - 1];
    }

    return 0;
}
