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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> hist(n, vector<int>(m));
    {
        vector<string> grid(n);
        for (int i = 0; i < n; i++) { cin >> grid[i]; }
        for (int i = 0; i < m; i++) { hist[0][i] = grid[0][i] == '.'; }
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i + 1][j] == '.') { hist[i + 1][j] = hist[i][j] + 1; }
            }
        }
    }

    vector<vector<ll>> pref(n + 2, vector<ll>(m + 2));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i * j <= k) { pref[i + 1][j + 1] = 1; }
            pref[i + 1][j + 1] += pref[i + 1][j];
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            pref[i + 1][j + 1] += pref[i][j + 1];
            pref[i + 1][j + 1] += pref[i + 1][j];
            pref[i + 1][j + 1] -= pref[i][j];
        }
    }

    ll cnt = 0;
    struct Node {
        int pos, val, left = -1, right = -1;
        int in, out;
    };

    for (int i = 0; i < n; i++) {
        auto cartMin = minCartesianTree(hist[i]);
        vector<Node> t(m);
        int root;
        for (int j = 0; j < m; j++) {
            t[j].pos = j;
            t[j].val = hist[i][j];
            t[j].in = j;
            t[j].out = j;
            if (cartMin[j] == -1) {
                root = j;
                continue;
            }
            if (j < cartMin[j]) { t[cartMin[j]].left = j; }
            if (cartMin[j] < j) { t[cartMin[j]].right = j; }
        }
        auto dfs = [&](auto &&self, int actual) -> void {
            int left = t[actual].left, right = t[actual].right;
            if (left != -1) {
                self(self, left);
                t[actual].in = t[left].in;
            }
            if (right != -1) {
                self(self, right);
                t[actual].out = t[right].out;
            }
            ll interval = (t[actual].out - t[actual].in + 1);

            ll height = t[actual].val;
            cnt += pref[height + 1][interval + 1];
            if (cartMin[actual] != -1) {
                ll remHeight = hist[i][cartMin[actual]];
                cnt -= pref[remHeight + 1][interval + 1];
            }
        };
        dfs(dfs, root);
    }
    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
