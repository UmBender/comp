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
constexpr int MAX_N = 2e5 + 100;
int n, q;
vector<int> adj[MAX_N];
int subTreeSizes[MAX_N];
int heavyChild[MAX_N];
int labels[MAX_N];
int heads[MAX_N];
int label = 0;
int t[4 * MAX_N];
int heights[MAX_N];
int bl[MAX_N][32];
int parents[MAX_N];
template <class S, S (*op)(S, S), S (*e)()> struct Segtree {
    vector<S> t;
    int n;
    Segtree(int N) : t(2 * N, e()), n(N) {}
    void set(int i, S value) {
        t[i += n] = value;
        for (i >>= 1; i; i >>= 1)
            t[i] = op(t[i << 1], t[i << 1 | 1]);
    } // 630e57
    S query(int l, int r) {
        S al = e(), ar = e();
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                al = op(al, t[l++]);
            if (r & 1)
                ar = op(t[--r], ar);
        }
        return op(al, ar);
    } // 9ee903
};

int join(int first, int second) { return max(first, second); }
int e() { return 0; }
using St = Segtree<int, join, e>;

St st(MAX_N);

void dfs(int node, int parent = -1, int height = 0) {
    subTreeSizes[node] = 1;
    heavyChild[node] = -1;
    heights[node] = height;
    parents[node] = parent;
    int mmax = 0;
    for (int next : adj[node]) {
        if (next == parent) {
            continue;
        }
        dfs(next, node, height + 1);
        subTreeSizes[node] += subTreeSizes[next];
        if (subTreeSizes[next] > mmax) {
            mmax = subTreeSizes[next];
            heavyChild[node] = next;
        }
    }
}

void labelNodes(int node, int parent, int head) {
    labels[node] = label++;
    heads[node] = head;
    if (heavyChild[node] == -1) {
        return;
    }
    labelNodes(heavyChild[node], node, head);
    for (int next : adj[node]) {
        if (next == parent || next == heavyChild[node]) {
            continue;
        }
        labelNodes(next, node, next);
    }
}

void segtree(int base[]) {}
void build(int tp, int tl, int tr, int base[]) {
    if (tr == tl) {
        t[tp] = base[tr];
        return;
    }
    if (tr < tl) {
        return;
    }
    int tm = (tr + tl) / 2;
    build(tp * 2, tl, tm, base);
    build(tp * 2 + 1, tm + 1, tr, base);
    int first = t[tp * 2 - 1];
    int second = t[tp * 2];
    t[tp] = max(first, second);
}
void update(int tp, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        t[tp] = val;
        return;
    }
    assert(tr > tl);
    int tm = (tl + tr) / 2;
    if (pos <= tm) {
        update(tp * 2, tl, tm, pos, val);
    } else {
        update(tp * 2 + 1, tm + 1, tr, pos, val);
    }

    int first = t[tp * 2];
    int second = t[tp * 2 + 1];
    t[tp] = max(first, second);
}

int query(int tp, int tl, int tr, int l, int r) {
    if (tl == l && tr == r) {
        return t[tp];
    }
    if (tl > r || tr < l) {
        return 0;
    }
    int tm = (tl + tr) / 2;
    int first = query(tp * 2, tl, tm, l, min(tm, r));
    int second = query(tp * 2 + 1, tm + 1, tr, max(tm + 1, l), r);
    return max(first, second);
}

inline int query(int l, int r) { return query(1, 0, n - 1, l, r); }
inline void update(int pos, int val) { update(1, 0, n - 1, pos, val); }

void binaryLift() {
    for (int i = 0; i < n; i++) {
        bl[i][0] = parents[i];
    }
    for (int i = 1; i < 32; i++) {
        for (int j = 0; j < n; j++) {
            int up = bl[j][i - 1];
            if (up == -1) {
                bl[j][i] = -1;
                continue;
            }
            int upper = bl[upper][i - 1];
            bl[j][i] = upper;
        }
    }
}

int fixHeight(int node, int otherHeight) {
    int delta = heights[node] - otherHeight;
    int actual = node;
    for (int i = 0; i < 32; i++) {
        if (actual == -1) {
            continue;
        }
        if (delta & 1) {
            actual = bl[actual][i];
        }
        delta >>= 1;
    }
    return actual;
}
int lca(int first, int second) {
    if (heights[first] < heights[second]) {
        second = fixHeight(second, heights[first]);
    }
    if (heights[second] < heights[first]) {
        first = fixHeight(first, heights[second]);
    }
    if (first == second) {
        return first;
    }
    for (int i = 31; i >= 0; i--) {
        if (bl[first][i] == bl[second][i]) {
            continue;
        }
        first = bl[first][i], second = bl[second][i];
    }
    return bl[first][0];
}

void buildPath(int first, int second, vector<pii> &path) {
    if (heads[first] == heads[second]) {
        path.push_back({first, second});
        return;
    }
    if (heights[first] > heights[second]) {
        path.push_back({first, heads[first]});
        int newFirst = parents[heads[first]];
        buildPath(newFirst, second, path);
    } else {
        path.push_back({second, heads[second]});
        int newSecond = parents[heads[second]];
        buildPath(first, newSecond, path);
    }
}

int treeQuery(int first, int second) {
    if (heads[first] == heads[second]) {
        return st.query(min(labels[first], labels[second]),
                        max(labels[first], labels[second]) + 1);
    }

    if (heights[heads[first]] < heights[heads[second]]) {
        int temp = st.query(labels[heads[second]], labels[second] + 1);
        return max(temp, treeQuery(first, parents[heads[second]]));
    }
    int temp = st.query(labels[heads[first]], labels[first] + 1);
    return max(temp, treeQuery(parents[heads[first]], second));
}

int main() {
    for (int i = 0; i < MAX_N; i++) {
        labels[i] = -1;
    }
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    int v[n];
    for (int &vi : v) {
        cin >> vi;
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0);
    labelNodes(0, -1, 0);
    for (int i = 0; i < n; i++) {
        st.set(labels[i], v[i]);
    }

    while (q--) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            int s, x;
            cin >> s >> x;
            s--;
            st.set(labels[s], x);
        } else {
            int a, b;
            cin >> a >> b;
            a--, b--;

            cout << treeQuery(a, b) << endl;
        }
    }

    return 0;
}
