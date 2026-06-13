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
constexpr ll MAX_N = 2e5 + 100;
int n;
vector<int> adj[MAX_N];
ll subTree[MAX_N];
ll dist[MAX_N];
int nextList[MAX_N];
ll dp1[MAX_N];
ll dp2[MAX_N];

void dfs1(int node, int length = 1, int parent = -1) {
    nextList[node] = -1;
    for (int nextNode : adj[node]) {
        if (nextNode == parent) {
            continue;
        }
        dfs1(nextNode, length + 1, node);
        if (dist[node] < dist[nextNode]) {
            dist[node] = dist[nextNode];
            nextList[node] = nextNode;
        }
    }
}

vector<int> buildPath(int node) {
    vector<int> path;
    while (node != -1) {
        path.push_back(node);
        node = nextList[node];
    }
    return path;
}

void dfs2(int node, int parent = -1) {
    int actual = 1;
    for (int next : adj[node]) {
        if (next == parent) {
            continue;
        }
        dfs2(next, node);
        actual += subTree[next];
        dp1[node] += dp1[next];
        dp1[node] += subTree[next];
    }
    subTree[node] = actual;
}

void dfs3(int node, int parent = -1) {
    if (parent == -1) {
        dp2[node] = dp1[node];
    }
    for (int next : adj[node]) {
        if (next == parent) {
            continue;
        }
        dp2[next] = dp2[node];
        dp2[next] -= subTree[next];
        dp2[next] += n - subTree[next];
        dfs3(next, node);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs1(0);
    vector<int> path1 = buildPath(0);
    int mostDist = path1.back();
    dfs1(mostDist);
    vector<int> path2 = buildPath(mostDist);
    int middle = path2[path2.size() / 2];
    dfs2(middle);
    dfs3(middle);
    for (int i = 0; i < n; i++) {
        cout << dp2[i] << " \n"[i == n - 1];
    }

    return 0;
}
