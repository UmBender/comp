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

vector<ll> adj[(int)(2e5 + 100)];
bool removed[(int)(2e5 + 100)];
int subtreeSize[(int)(2e5 + 100)];
int curr[(int)(2e5 + 100)];
int allDist[(int)(2e5 + 100)];
ll ans = 0;
int n, k, curr_sz;
int getSubTree(int v, int p = -1) {
    subtreeSize[v] = 1;
    for (int next : adj[v]) {
        if (next == p || removed[next]) {
            continue;
        }
        subtreeSize[v] += getSubTree(next, v);
    }
    return subtreeSize[v];
}

int getCentroid(int v, int treeSize, int p = -1) {
    for (int next : adj[v]) {
        if (next == p || removed[next])
            continue;
        if (subtreeSize[next] * 2 > treeSize) {
            return getCentroid(next, treeSize, v);
        }
    }
    return v;
}

void getDistances(int v, int p, int dist) {
    if (dist > k)
        return;
    curr[curr_sz++] = dist;
    for (int next : adj[v]) {
        if (next == p || removed[next])
            continue;
        getDistances(next, v, dist + 1);
    }
}

void processCentroid(int centroid) {
    allDist[0] = 1;
    vector<int> visitedDists;
    for (int next : adj[centroid]) {
        if (removed[next]) {
            continue;
        }
        curr_sz = 0;
        getDistances(next, centroid, 1);
        for (int i = 0; i < curr_sz; i++) {
            ans += allDist[k - curr[i]];
        }
        for (int i = 0; i < curr_sz; i++) {
            allDist[curr[i]]++;
            visitedDists.push_back(curr[i]);
        }

    }
    for (int d: visitedDists) {
        allDist[d] = 0;
    }
    allDist[0] = 0;
}

void dec(int v) {
    int treeSize = getSubTree(v);
    int centroid = getCentroid(v, treeSize);
    processCentroid(centroid);
    removed[centroid] = true;
    for (int u : adj[centroid]) {
        if (!removed[u]) {
            dec(u);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dec(0);
    cout << ans << endl;
    return 0;
}
