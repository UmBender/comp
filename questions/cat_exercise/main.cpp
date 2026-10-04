#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
template <typename... T> void _dbg(const char *names, T &&...args) {
    cerr << "[" << names << "] =";
    ((cerr << ' ' << args), ...);
    cerr << endl;
}
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...)
#endif

using ll = long long;

// Title: Cartesian tree (max)
// Description: Parent of each index in the max Cartesian tree of a vector (maximum at the root, -1
// for it). Usage:
//   vector<int> par = maxCartesianTree(a);   // ties: the leftmost one is the ancestor
//   In-order traversal of the tree is 0, 1, ..., n - 1.
// Complexity: O(n).
template <class T> vector<int> maxCartesianTree(const vector<T> &a) {
    int n = (int)a.size();
    vector<int> par(n, -1), st; // st: the right spine, top = deepest
    for (int i = 0; i < n; i++) {
        int last = -1;
        while (!st.empty() && a[st.back()] < a[i]) last = st.back(), st.pop_back();
        if (last != -1) par[last] = i; // the popped chain becomes i's left subtree
        if (!st.empty()) par[i] = st.back();
        st.push_back(i);
    }
    return par;
}
// End: Cartesian tree (max)

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    auto parents = maxCartesianTree(p);
    struct Node {
        ll pos, val, left = -1, right = -1, longest = 0;
    };

    vector<Node> nodes(n);
    int root = -1;
    for (int i = 0; i < n; i++) {
        nodes[i].pos = i;
        nodes[i].val = p[i];
        if (parents[i] != -1) {
            if (i < parents[i]) {
                nodes[parents[i]].left = i;
            } else {
                nodes[parents[i]].right = i;
            }
        } else {
            root = i;
        }
    }
    auto dfs = [&](auto &&self, int actual) -> void {
        int left = nodes[actual].left, right = nodes[actual].right;
        if (left != -1) {
            self(self, left);
            ll calc = abs(nodes[actual].pos - nodes[left].pos);
            nodes[actual].longest = max(calc + nodes[left].longest, nodes[actual].longest);
        }
        if (right != -1) {
            self(self, right);
            ll calc = abs(nodes[actual].pos - nodes[right].pos);
            nodes[actual].longest = max(calc + nodes[right].longest, nodes[actual].longest);
        }
    };
    dfs(dfs, root);
    cout << nodes[root].longest << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
