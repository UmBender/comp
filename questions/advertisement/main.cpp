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

// Title: Cartesian tree (min)
// Description: Parent of each index in the min Cartesian tree of a vector (minimum at the root, -1
// for it). Usage:
//   vector<int> par = minCartesianTree(a);   // ties: the leftmost one is the ancestor
//   In-order traversal of the tree is 0, 1, ..., n - 1.
// Complexity: O(n).
template <class T> vector<int> minCartesianTree(const vector<T> &a) {
    int n = (int)a.size();
    vector<int> par(n, -1), st; // st: the right spine, top = deepest
    for (int i = 0; i < n; i++) {
        int last = -1;
        while (!st.empty() && a[st.back()] > a[i]) last = st.back(), st.pop_back();
        if (last != -1) par[last] = i; // the popped chain becomes i's left subtree
        if (!st.empty()) par[i] = st.back();
        st.push_back(i);
    }
    return par;
}
// End: Cartesian tree (min)

void solve() {
    int n;
    cin >> n;
    vector<int> k(n);
    for (int i = 0; i < n; i++) cin >> k[i];
    auto cart = minCartesianTree(k);
    struct Node {
        ll left, right;
        ll val, in, out, pos;
    };
    vector<Node> nodes(n);
    for (int i = 0; i < n; i++) { nodes[i] = {-1, -1, k[i], i, i, i}; }
    int root = 0;
    for (int i = 0; i < n; i++) {
        if (cart[i] != -1) {
            if (i < cart[i]) {
                nodes[cart[i]].left = i;
            } else {
                nodes[cart[i]].right = i;
            }
        } else {
            root = i;
        }
    }

    ll mmax = 0;

    auto dfs = [&](auto &&self, int actual) -> void {
        int left = nodes[actual].left, right = nodes[actual].right;
        if (left != -1) {
            self(self, left);
            nodes[actual].in = nodes[left].in;
        }
        if (right != -1) {
            self(self, right);
            nodes[actual].out = nodes[right].out;
        }
        ll calc = (nodes[actual].out - nodes[actual].in + 1) * nodes[actual].val;
        mmax = max(mmax, calc);
    };

    dfs(dfs, root);
    cout << mmax << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
