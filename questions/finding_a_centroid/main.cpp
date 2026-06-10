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
vector<vector<int>> adj;
vector<int> subTreeSize;
int n;

void dfs(int actual, int last) {
    int acc = 1;
    for (int next : adj[actual]) {
        if (next == last) {
            continue;
        }
        dfs(next, actual);
        acc += subTreeSize[next];
    }
    subTreeSize[actual] = acc;
}

int centroid(int actual, int last) {
    for (int next : adj[actual]) {
        if (subTreeSize[next] > n / 2) {
            subTreeSize[actual] = n - subTreeSize[next];
            return centroid(next, actual);
        }
    }
    return actual;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    adj = vector<vector<int>>(n);
    subTreeSize = vector<int>(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0, -1);
    cout << centroid(0, -1) + 1 << endl;

    return 0;
}
