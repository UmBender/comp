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
constexpr int MAX_N = 200100;
ll bit[MAX_N];

vector<int> adj[MAX_N];
bool used[MAX_N];
int reset[MAX_N];
int subTreeSize[MAX_N];
ll dists[MAX_N];
int distSz = 0;
int resetSz = 0;
ll acc = 0;
int n, k1, k2;

void update(int pos, int delta) {
    pos++;
    for (; pos < MAX_N; pos += (-pos & pos)) {
        bit[pos - 1] += delta;
    }
}

ll query(int right) {
    ll acc = 0;
    for (; right > 0; right -= (-right & right)) {
        acc += bit[right - 1];
    }
    return acc;
}

ll query(int left, int right) {
    ll first = query(right);
    ll second = query(left);
    return first - second;
}

void countSubTree(int node, int parent = -1) {
    subTreeSize[node] = 1;
    for (int next : adj[node]) {
        if (next == parent)
            continue;
        if (used[next]) {
            continue;
        }
        countSubTree(next, node);
        subTreeSize[node] += subTreeSize[next];
    }
}

int findCentroid(int node, int n, int parent = -1) {
    for (int next : adj[node]) {
        if (next == parent) {
            continue;
        }
        if (used[next]) {
            continue;
        }
        if (subTreeSize[next] * 2 > n) {
            return findCentroid(next, n, node);
        }
    }
    return node;
}

void calcDists(int node, int parent, int dist) {
    dists[distSz++] = dist;
    for (int next : adj[node]) {
        if (used[next]) {
            continue;
        }
        if (next == parent) {
            continue;
        }
        calcDists(next, node, dist + 1);
    }
}

void subTreePathCount(int centroid) {

    for (int next : adj[centroid]) {
        if (used[next]) {
            continue;
        }
        calcDists(next, centroid, 1);
        int size = distSz;
        while (size) {
            size--;
            if (k2 - dists[size] >= 0) {
                acc += query(max(0ll, k1 - dists[size]), k2 - dists[size] + 1);
            }
        }
        while (distSz) {
            distSz--;
            update(dists[distSz], 1);
            reset[resetSz++] = dists[distSz];
        }
    }
    while (resetSz) {
        resetSz--;
        update(reset[resetSz], -1);
    }
}

void solve(int node, int parent = -1) {
    countSubTree(node);
    int centroid = findCentroid(node, subTreeSize[node]);
    subTreePathCount(centroid);
    used[centroid] = true;
    for (int next : adj[centroid]) {
        if (used[next]) {
            continue;
        }
        solve(next, centroid);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k1 >> k2;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    update(0, 1);
    solve(0);
    cout << acc << endl;
    return 0;
}
