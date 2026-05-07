#include <bits/stdc++.h>

using namespace std;
using i32 = int;
using i64 = long long;
#define int i64

const int MOD = 998244353;

void solution();
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; 
    cin >> t;
    while (t--) {
        solution();
    }
    return 0;
}


void solution() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> counter(n + 1);
    vector<int> dp(n + 1);
    for (int k = 0; k < m; k++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }


    queue<int> val;
    val.push(1);
    vector<bool> used(n + 1);
    while (!val.empty()) {
        int actual = val.front();
        val.pop();
        for (auto next: adj[actual]) {
            counter[next]++;
            if (!used[next]) {
                val.push(next);
                used[next] = true;
            }
        }
    }

    val.push(1);
    dp[1] = 1;
    while (!val.empty()) {
        int actual = val.front();
        val.pop();
        for (int next: adj[actual]) {
            dp[next] += dp[actual];
            dp[next] %= MOD;
            counter[next]--;
            if (counter[next] == 0) {
                val.push(next);
            }
        }
    }

    cout << dp[n] << endl;

}


