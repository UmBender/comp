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
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    struct Node {
        set<int> child;
        int maxPath, value;
    };
    auto cart = maxCartesianTree(h);
    vector<Node> t(n);
    for (int i = 0; i < n; i++) {
        t[i].maxPath = 1;
        t[i].value = h[i];
        if (cart[i] != -1) { t[cart[i]].child.insert(i); }
    }

    int root = 0;
    for (int i = 0; i < n; i++) {
        if (cart[i] == -1) {
            root = i;
            break;
        }
    }
    auto dfs = [&](auto &&self, int actual, int last) -> void {
        t[actual].maxPath = 1;
        for (int next : t[actual].child) {
            self(self, next, actual);
            if (next < actual) {
                t[actual].maxPath = max(t[actual].maxPath, t[next].maxPath + 1);
            } else {
                if (h[next] == h[actual]) {
                    t[actual].maxPath = max(t[actual].maxPath, t[next].maxPath);
                } else {
                    t[actual].maxPath = max(t[actual].maxPath, t[next].maxPath + 1);
                }
            }
        }
    };
    dfs(dfs, root, -1);
    int mmax = 0;
    for (int i = 0; i < n; i++) { mmax = max(mmax, t[i].maxPath); }
    cout << mmax << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
